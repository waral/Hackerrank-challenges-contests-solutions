//
//  main.cpp
//  sams_number_matrix_exp
//
//  Created by Michał Warchalski on 03/06/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//


#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;
long long s, m, d;
long long MOD = 1e9 + 9;
vector<vector<long long>> Q(111, vector<long long>(111, 0));
vector<long long> DP(111,0);
vector<vector<long long>> DP0(11, vector<long long>(11, 0));
long long Answer = 0;
vector<vector<long long>> PowerResult(111, vector<long long> (111));
vector<vector<long long>> mult(111, vector<long long> (111, 0));

void PrintArr(vector<vector<long long>> A, long long size)
{
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
     cout << endl;
     cout << endl;
     cout << endl;
     cout << endl;
}

void PrintVec(vector<long long> A, long long size)
{
    for (int j = 1; j <= size; j++)
    {
        cout << A[j] <<endl;
    }
    cout << endl;
}

void PrepareDP()
{
    for (int i = 1; i <= m; i++)
    {
        DP0[i][i] = 1;
    }
    
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 1; k <= m; k++)
            {
                if (abs(j - k) <= d and i > j)
                {
                    DP0[i][j] = DP0[i][j] + DP0[i - j][k];
                }
                
            }
        }
    }
    
    
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            DP[m*(m-i) + j] = DP0[i][j];
        }
    }
    
}

void multiply_matrix(vector<vector<long long>> a, vector<vector<long long>> b, long long n)
{
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            mult[i][j] = 0;
            for (int k = 1; k <= n; k++)
            {
                mult[i][j] = (mult[i][j] + a[i][k]*b[k][j]) % MOD;
            }
        }
    }
    
}

void multiply_vec(vector<vector<long long>> a, vector<long long> &b, long long n)
{
    vector<long long> mul(n + 1, 0);
    
    for (int i = 1; i <= n; i++)
    {
        mul[i] = 0;
            for (int k = 1; k <= n; k++)
            {
                mul[i] = (mul[i] + a[i][k]*b[k]) % MOD;
            }
    }
    
    for (int i=1; i<= n; i++)
    {
        b[i] = mul[i];
    }
    
}

void matpow(vector<vector< long long >> Z, long long n)
{
    for (int i = 1; i <= m*m; i++)
    {
        PowerResult[i][i] = 1;
    }
    
    while(n>0)
    {
        if(n&1)
        {
            multiply_matrix(PowerResult,Z , m*m);
            
            for(int i = 1;i <= m*m; i++)
                for(int j = 1; j <= m*m; j++)
                    PowerResult[i][j]=mult[i][j];
        }
        multiply_matrix(Z, Z, m*m);
        
        for(int i = 1; i <= m*m; i++)
            for(int j = 1; j <= m*m ;j++)
                Z[i][j]=mult[i][j];
        
        n=n/2;
    }
    return;
    
}

void Solve()
{
    
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (abs(i - j) <= d)
            {
                Q[i][(i-1)*m + j] = 1;
            }
        }
    }

    
    for (int i = 1; i<= m*m - m; i++)
    {
        Q[i + m][i] = 1;
    }
    
    if (s <= m)
    {
        for (int i = 1; i <= m; i++)
        {
            Answer = (Answer + DP[(s-1)*m + i]) % MOD;
        }
        
        return;
    }
    
    matpow(Q, s - m);
    multiply_vec(PowerResult, DP, m*m);
    
    for (int i = 1; i <= m; i++)
    {
        Answer = (Answer + DP[i]) % MOD;
    }
    
    
}

int main()
{
//    freopen("/Users/Waral/Documents/Coding/Algorithms and Data structures/sams_number_matrix_exp/test.txt", "r", stdin);
//    freopen("/Users/Waral/Documents/Coding/Algorithms and Data structures/sams_number_matrix_exp/testout.txt", "w", stdout);
    
    cin >> s >> m >> d;
    PrepareDP();
    Solve();
    cout << Answer << endl;
    
    return 0;
}







