//
//  main.cpp
//  coinage
//
//  Created by Michał Warchalski on 25/05/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

long long Ways1[1001];  // av. coins 2, 1
long long Ways2[1001];  // av. coins 10, 5
int T, N;
int Coins1, Coins2, Coins5, Coins10;
long long Answer = 0;

void SolvePrep()
{
    Answer = 0;
    
    for (int i = 0; i <= N; i++)
    {
        Ways1[i] = 0;
        Ways2[i] = 0;
    }
    
    for (int n = 0; n <= N; n++)
    {
        for (int i = 0; i <= n; i+=2)
        {
            if ((i/2) <= Coins2 and n - i <=  Coins1)
            {
                Ways1[n]++;
            }
        }

    }
    
    for (int n = 0; n <= N; n+=5)
    {
        for (int i = 0; i <= n; i+=10)
        {
            if ( (i/10) <= Coins10 and (n-i)/5 <= Coins5)
            {
                Ways2[n]++;
            }
        }
    }
}

void Solve()
{
    for (int i = 0; i <= N; i++)
    {
        Answer += Ways1[i]*Ways2[N-i];
    }
}

int main()
{
    
    cin >> T;
    
    for (int t = 0; t < T; t++)
    {
        cin >> N;
        cin >> Coins1 >> Coins2 >> Coins5 >> Coins10;
        SolvePrep();
        Solve();
        cout << Answer << endl;
        
    }
    
    return 0;
}

