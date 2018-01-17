//
//  main.cpp
//  lego_blocks
//
//  Created by Michał Warchalski on 06/04/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
using namespace std;

long long BIG = 1000000007;
long long Ways[1001][1001];
long long HeightOnePossibilities[1001];
long long Illegal[1001][1001];

long long HeightOne(int Length)
{
    if (Length < 0)
    {
        return 0;
    }
    
    if (Length == 0)
    {
        return 1;
    }
    
    if (HeightOnePossibilities[Length] == -1)
    {
        HeightOnePossibilities[Length] = 0;
        
        for (int i = 1; i < 5; i++)
        {
            HeightOnePossibilities[Length] += HeightOne(Length - i);
            //cout <<"tralala"<<endl;
        }
    }
    
    
    return HeightOnePossibilities[Length] % BIG;
}

long long WaysToBuild(int Height, int Length);
long long IllegalBuildings(int Height, int Length);

long long IllegalBuildings(int Height, int Length)
{
    if (Length <= 0)
    {
        return 0;
    }
    
    if (Length == 1 or Length == 0)
    {
        return 0;
    }
    
    if (Illegal[Height][Length] == -1)
    {
        Illegal[Height][Length] = 0;
       // cout<<"hey "<<Height<<" "<<Length<<endl;
        for (int i = 1; i < Length; i++)
        {
            Illegal[Height][Length] = (Illegal[Height][Length] +  WaysToBuild(Height, i) * WaysToBuild(Height, Length - i) + WaysToBuild(Height, i) * IllegalBuildings(Height, Length - i)) % BIG;
        }
    }
    
    
    return Illegal[Height][Length] % BIG;
}

long long WaysToBuild(int Height, int Length)
{
    //long NumberOfWays = 0;
    
    if (Height < 0 or Length < 0)
    {
        return 0;
    }
    
    if (Height == 0 or Length == 0)
    {
        return 1;
    }
    
    if (Height == 1 and Length < 5)
    {
        return 1;
    }
    
    if (Height == 1 and Length > 4)
    {
        return 0;
    }
    
    if (Length == 1)
    {
        return 1;
    }
    
    if (Ways[Height][Length] == -1)
    {
        Ways[Height][Length] = 1;
        
        for (int i = 0; i < Height; i++)
        {
            Ways[Height][Length] = (Ways[Height][Length]*HeightOne(Length)) % BIG;
        }
        
        Ways[Height][Length] = (Ways[Height][Length] - IllegalBuildings(Height, Length) + BIG )% BIG;
        

    }
    

    return Ways[Height][Length] % BIG;
}

int main(int argc, const char * argv[])
{
    
    int T;
    
    cin >> T;
    
    for (int i = 0; i < 1001; i++)
    {
        for (int j = 0; j < 1001; j++)
        {
            Ways[i][j] = -1;
            Illegal[i][j] = -1;
        }
    }
    
    for (int i = 0; i < 1001; i++)
    {
        HeightOnePossibilities[i] = -1;
    }

    
    for (int q = 0; q < T; q++)
    {
        int N, M;
        
        cin>> N >> M;
        
        cout<< WaysToBuild(N, M) << endl;
        //cout <<"Ways: "<< WaysToBuild(N, M) << endl;
        //cout <<"Illegal: "<< IllegalBuildings(N, M) << endl;
    }
    
    //cout << HeightOne(T) << endl;
    
        return 0;
}
