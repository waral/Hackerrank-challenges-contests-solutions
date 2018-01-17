//
//  main.cpp
//  BIT_direct_connections
//
//  Created by Michał Warchalski on 10/05/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long const Mod = 1e9 + 7;
long long const MaxSize = 2*(1e5);
vector<long long> SumApp(MaxSize);
vector<long long> SumDist(MaxSize);

long long GetSumMod(vector<long long> &B, long long Index)
{
    long long Answer = 0;
    
    while(Index)
    {
        Answer = (Answer + B[Index]) % Mod;
        Index -= (Index & -Index);
    }
    
    return Answer;
}

void UpdateSumMod(vector<long long> &B, long long Index, long long Val)
{
    while (Index <= MaxSize)
    {
        B[Index] = (B[Index] + Val) % Mod;
        Index += (Index & -Index);
    }
}

long long  Cable(vector<long long> Cor, vector<pair<long long, long long>> PopSorted, vector<long long> Order, long long N)
{
    long long Ans = 0;
    
    for (long long i = 1; i < N+1; i++)
    {
        long long Ord = Order[PopSorted[i].second];
        long long Dist = Cor[PopSorted[i].second];
        long long HowManyLeft = GetSumMod(SumApp, Ord);
        long long HowManyRight = (GetSumMod(SumApp, N+1) - GetSumMod(SumApp, Ord) + Mod) % Mod;
        long long SumDistLeft = GetSumMod(SumDist, Ord);
        long long SumDistRight = (GetSumMod(SumDist, N+1) - GetSumMod(SumDist, Ord) + Mod) % Mod;
        long long Pop = PopSorted[i].first;
        long long LeftInc = (Pop * ((HowManyLeft* Dist) % Mod - SumDistLeft  + Mod)) % Mod;
        long long RightInc = (Pop * (SumDistRight - (HowManyRight* Dist) % Mod + Mod)) % Mod;
        
        Ans = (Ans + LeftInc + RightInc) % Mod;
        UpdateSumMod(SumApp, Ord, 1);
        UpdateSumMod(SumDist, Ord, Dist);
        
    }
    
    
    return Ans;
}

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++)
    {
        for (long long i = 0; i < MaxSize; i++)//cleaning up the previous test case
        {
            SumApp[i] = 0;
            SumDist[i]= 0;
        }
        
        long long N;
        cin >> N;
        vector<long long>  Coordinates(N + 1);
        vector<pair<long long, long long>>  CoordinatesAux(N + 1);// Auxiliary to order cities: coordinate, city number
        vector<pair<long long, long long>>  Population(N + 1);
        vector<long long> Ordering(N + 1); // which one is city i from the left?
        
        for (long long i = 1; i < N + 1; i++) // reading in Coordinates
        {
            cin >> Coordinates[i];
            CoordinatesAux[i].first = Coordinates[i];
            CoordinatesAux[i].second = i;
            
        }
        
        sort(CoordinatesAux.begin() + 1, CoordinatesAux.end()); //sorting CoordinatesAux to see what is the ordering
        
        for (long long i = 1; i < N + 1; i++)
        {
            Ordering[CoordinatesAux[i].second] = i; //saving the ordering + 1
        }
        
        for (long long i = 1 ; i < N + 1; i++) //reading in Population
        {
            cin >> Population[i].first;
            Population[i].second = i ;
        }
        
        sort(Population.begin() + 1, Population.end()); //sorting Population
        cout << Cable(Coordinates, Population, Ordering, N) << endl;
    }
    
    
    return 0;
}
