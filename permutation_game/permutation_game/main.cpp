//
//  main.cpp
//  permutation_game
//
//  Created by Michał Warchalski on 29/04/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

long long const NUMBER = (1 << 15);
int Bin[NUMBER][15];
int WhoWins[NUMBER];
bool Considered[NUMBER];
vector<int> A(15);

int FirstNonzero(long long a)
{
    int answer = 0;
    
    while (a > 0)
    {
        answer++;
        
        a >>= 1;
    }
    
    return answer;
}


vector<int> BinaryDecomp(long long a)
{
    int size = FirstNonzero(a);
    vector<int> Decomp(size,0);
    
    for (int i = 0; i < size; i++)
    {
        if(a & 1)
        {
            Decomp[i] = 1;
        }
        //cout << Decomp[i]<< " ";
        a >>= 1;
    }
    //cout << endl;
    
    return Decomp;
}


void Binary()
{
    for (long long i = 0; i < NUMBER; i++)
    {
        vector<int> decomp = BinaryDecomp(i);
        int size = (int)decomp.size();
        
        for (int j = 0; j < size; j++)
        {
            Bin[i][j] = decomp[j];
        }
    }
}

char whoWins(long long a, int Player)
{
    if (Considered[a])
    {
        return WhoWins[a];
    }
    
    Considered[a] = true;
    
    int Temp = -1;
    bool NonIncr = false;
    
//    cout << "Current sequence: " << endl;
//    for(int i = 0; i < 15; i++)
//    {
//        if (Bin[a][i] == 1)
//        {
//            cout << A[i] << " ";
//        }
//    }
//    cout << endl;
    
    for (int i = 0; i < 15; i++)
    {
        if (Bin[a][i] == 1)
        {
            if (Temp == -1)
            {
                Temp = i;
            }

            if (A[Temp] > A[i])
            {
                //cout << A[Temp]<<" > "<< A[i] << endl;
                NonIncr = true;
                break;
            }
            Temp = i;
        }
    }
    
    if (NonIncr == false) //in this case we know that the other player won one step earlier
    {
        //cout <<"Increasing " << endl;
        WhoWins[a] = (Player + 1) % 2;
        return WhoWins[a];
    }
    
    //otherwise consider smaller cases
    
    for (int i = 0; i < 15; i++)
    {
        if (Bin[a][i] == 1 and whoWins(a - (1 << i), (Player + 1)%2) == Player)
        {
            //cout << "Player "<<Player<<" Winning "<<i<<endl;
            WhoWins[a] = Player;
            return WhoWins[a];
        }
    }
    
    WhoWins[a] = (Player + 1) % 2;
    return WhoWins[a];

}

int main(int argc, const char * argv[])
{
    Binary();
    
//    for (long long i = 0; i < NUMBER; i++)
//    {
//        for (int j = 0; j < 15; j++)
//        {
//            cout << Bin[i][j];
//        }
//        cout<<endl;
//    }
    
    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++)
    {
        for (long long i = 0; i < NUMBER; i++)
        {
            Considered[i] = false;
        }
        
        int N;
        cin >> N;
        
        for (int j = 0; j < N; j++)
        {
            cin >> A[j];
        }
        
        long long elements = (1 << N) - 1;
        //cout << "elements : "<< elements << endl;
        int answer = whoWins(elements, 0);
        
        if (answer == 0)
        {
            cout << "Alice" << endl;
        }
        else cout << "Bob" << endl;
        
        
    }
    
    
    return 0;
}
