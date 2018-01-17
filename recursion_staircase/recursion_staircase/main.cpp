//
//  main.cpp
//  recursion_staircase
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

long long Ways[37];

long long NumberOfWays(int n)
{
    if (Ways[n] == -1)
    {
        Ways[n] = NumberOfWays(n-1) + NumberOfWays(n-2) + NumberOfWays(n-3);
        return Ways[n];
    }
    
    return Ways[n];
    
}


int main()
{
    int s;
    long long ans[5];
    cin >> s;
    
    for (int i = 0; i < 37; i++)
    {
        Ways[i]=-1;
    }
    
    Ways[0] = 1;
    Ways[1] = 1;
    Ways[2] = 2;
    
    for(int i = 0; i < s; i++)
    {
        int n;
        cin >> n;
        ans[i]=NumberOfWays(n);
    }
    
    for (int i; i < s; i++)
    {
        cout << ans[i] << endl;
    }
    
            
            
    return 0;
}

















