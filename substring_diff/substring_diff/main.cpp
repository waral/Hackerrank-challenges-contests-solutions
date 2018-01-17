//
//  main.cpp
//  substring_diff
//
//  Created by Michał Warchalski on 17/06/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int const MAX = 1501;
int T, S, N;
int MaxLen = 0;
int Max_i = 0, Max_j = 0;
string  P, Q;
int DP[MAX][MAX];


void Prepare()
{
    MaxLen = 0;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            DP[i][j] = 0;
        }
    }
}

void Solve()
{
    N = (int) P.length();
    
    for (int i = 0; i < N; i++)
    {
        int Diff = 0;
        int Len = 1;
        
        while (i + Len - 1 < N)
        {
            if (P[i + Len - 1] != Q[Len - 1])
            {
                Diff++;
                if(Diff > S) break;
            }
            //cout <<"i = "<<i <<" letters " << P[i + Len - 1] <<" , " << Q[Len - 1] << endl;
            //cout <<"Len = "<<Len <<endl;
            Len++;
        }
        DP[i][0] = Len - 1;
        //MaxLen = max(DP[i][1], MaxLen);
        if (DP[i][0] > MaxLen)
        {
            MaxLen = DP[i][0];
            Max_i = i;
            Max_j = 0;
        }
    }
   // cout << "1 " << MaxLen << endl;
    
    for (int j = 0; j < N; j++)
    {
        int Diff = 0;
        int Len = 1;
        
        while (j + Len - 1 < N)
        {
            if (P[Len - 1] != Q[j + Len - 1])
            {
                Diff++;
                if (Diff > S) break;
            }
            //cout <<"j = "<<j <<" letters " << P[Len - 1] <<" , " << Q[ j + Len - 1] << endl;
            //cout <<"Len = "<<Len <<endl;
            Len++;
        }
        DP[0][j] = Len - 1;
        //MaxLen = max(DP[1][j], MaxLen);
        if (DP[0][j] > MaxLen)
        {
            MaxLen = DP[0][j];
            Max_i = 0;
            Max_j = j;
        }

    }
   // cout << "2 " << MaxLen << endl;
    
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < N; j++)
        {
            int InitLen = DP[i-1][j-1] - 1; //length will be at least this one
            
            if (i + InitLen - 1 >= N - 1 or j + InitLen - 1 >= N - 1) //too long
            {
                DP[i][j] = InitLen;
                continue;
            }
            
            if(P[i-1] == Q[j-1])
            {
                DP[i][j] = InitLen;
                continue; //first characters are the same, so we can't prolong the sequence, nothing to do
            }
            
            InitLen++;
            int k = i + InitLen;
            int l = j + InitLen;
            //we can skip k-1, l-1, because for sure P[k-1] != Q[l-1], otherwise previous could have been longer

            while( P[k] == Q[l] and k < N and l < N)
            {
                k++;
                l++;
                InitLen++;
            }
            DP[i][j] = InitLen;
            //MaxLen = max(DP[i][j], MaxLen);
            if (DP[i][j] > MaxLen)
            {
                MaxLen = DP[i][j];
                Max_i = i;
                Max_j = j;
            }

        }
    }
}

int main(int argc, const char * argv[])
{
    cin >> T;
    
    while (T--)
    {
        cin >> S >> P >> Q;
        Prepare();
        Solve();
        cout << MaxLen << endl;
       // cout << Max_i <<" " << Max_j << endl;
    }
    
    return 0;
}
