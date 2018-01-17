//
//  main.cpp
//  grid_walking
//
//  Created by Michał Warchalski on 20/04/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
#include <vector>

long long Mod = 1000000007;

using namespace std;

long long Walking1D[101][101][301]; // [X][D][M]

long long Factorial[301];

long long Bin[301][301];

long long GW[100][301]; //[FirstIndex][Length]

void FactorialMod()
{
    Factorial[0] = 1;
    
    for (int i = 1; i < 301; i++)
    {
        Factorial[i] = (Factorial[i-1]*i) % Mod;
        //cout<< Factorial[i] <<endl;
    }
    
    
}

long long modPow(long long a, long long x, long long p)
{
    long long ans = 1;
    
    while( x > 0)
    {
        if (x & 1)
        {
            ans = (ans * a) % p;
        }
        
        a = (a*a) % p;
        x >>= 1;
    }
    
    return ans;
}


long long Binomial(int N, int M)
{
    if (M > N)
    {
        return 0;
    }
    
    if (Bin[N][M] > 0)
    {
        return Bin[N][M];
    }
    
    long long Factor = (Factorial[N-M]*Factorial[M]) % Mod;
    
    Bin[N][M] = (Factorial[N] * modPow(Factor, Mod - 2, Mod)) % Mod;
    
    return Bin[N][M];
}

long long GridWalking1D(int X, int D, int M)
{
    //int wrong = 0;
    long long Walking = 0;
    
    if(X <= 0 or X > D)
    {
        return 0;
    }
    
    if (M == 0)
    {
        return 1;
    }
    
    if (Walking1D[X-1][D-1][M-1] > -1)
    {
        return Walking1D[X-1][D-1][M-1];
    }
    
    Walking = (Walking + GridWalking1D(X-1, D, M-1)) % Mod;
    Walking = (Walking + GridWalking1D(X+1, D, M-1)) % Mod;

    Walking1D[X-1][D-1][M-1] = Walking % Mod;

    return Walking1D[X-1][D-1][M-1];
    
}

void GridWalking(vector<int> X, vector<int> D, int M)
{
    int N = X.size();
    
    for (int m = 0; m <= M; m++)
    {
        GW[N-1][m] = GridWalking1D(X[N-1], D[N-1], m);
    }
    
    
    for (int i = N - 2; i > -1; i--)
    {
      
        for (int m = 0; m <= M; m++)// Calculating GW[i][m]
        {
            GW[i][m] = 0;
            for (int j = 0; j <= m; j++)
            {
                GW[i][m] = (GW[i][m] +  (((Binomial(m,j)*GridWalking1D(X[i], D[i], j))%Mod) * GW[i + 1][m - j]) % Mod) % Mod;
            }
            
        }
        
    }
    
}



int main(int argc, const char * argv[]) {
    
    for (int i1 = 0; i1 < 101; i1++)
    {
        for (int i2 = 0; i2 < 101; i2++)
        {
            for (int i3 = 0; i3 < 301; i3++)
            {
                Walking1D[i1][i2][i3] = -1;
            }
        }
    }
    
    FactorialMod();
    
    //cout<<Binomial(10, 3) << endl;
    
    int T;
    
    cin >> T;
    
    for (int q = 0; q < T; q++)
    {
        int N, M;
        
        
        cin>> N >> M;
        
        vector<int> x(N), D(N);
        
        for (int i = 0; i < N; i++)
        {
            cin>>x[i];
        }

        for (int i = 0; i < N; i++)
        {
            cin>>D[i];
        }
        
        GridWalking(x, D, M);
        
        cout<< GW[0][M] << endl;

    }
    
    
    return 0;
}
