//
//  main.cpp
//  knapsack
//
//  Created by Michał Warchalski on 28/05/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int const MAX = 2001;
int const INF = 1e7;
int T, n, k;
vector<int> a(MAX);
vector<int> Knap(MAX);
int Min = 0;

void Prepare()
{
    for (int i = 0 ; i <= MAX; i++)
    {
        Knap[i] = -INF;
    }
}

int Knapsack(int Sum)
{
    if (Sum < 0)
    {
        return -INF;
    }
    
    if (Knap[Sum] >= 0)
    {
        return Knap[Sum];
    }
    
    for (int i = 0; i < n; i++)
    {
        Knap[Sum] = max(Knap[Sum], a[i] + Knapsack(Sum - a[i]));
    }
    if (Knap[Sum] < 0) Knap[Sum] = 0;
    
    return Knap[Sum];
}

int main(int argc, const char * argv[])
{
    cin >> T;
    
    while (T--)
    {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Prepare();
        cout << Knapsack(k) << endl;
    }
    return 0;
}
