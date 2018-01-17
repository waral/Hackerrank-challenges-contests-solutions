//
//  main.cpp
//  coin_change
//
//  Created by Michał Warchalski on 21/03/17.
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

unsigned long long change[250][50];

unsigned long long make_change(vector<int> coins, int start, int money)
{
    if (money == 0)
    {
        return 1;
    }
    
    if (money < 0)
    {
        return 0;
    }
    
    if (change[money][start] == 0)
    {
        //change[money][start] = 0;
        
        for (int i = start; i < coins.size(); i++)
        {
            change[money][start] = change[money][start] + make_change(coins, i, money - coins[i]);
        }
        
        return change[money][start];
    }
    
    return change[money][start];
}

int main()
{
    
    int n;
    int m;
    
    cin >> n >> m;
    
    vector<int> coins(m);
    
    for(int coins_i = 0;coins_i < m;coins_i++)
    {
        cin >> coins[coins_i];
    }
    
    sort(coins.begin(),coins.end());
    
    for (int i = 0; i < 250; i++)
    {
        for (int j= 0; j < 50; j++)
        {
                change[i][j] = 0;
        }
        
    }
    
    cout << make_change(coins, 0, n) << endl;
    
    return 0;
}

