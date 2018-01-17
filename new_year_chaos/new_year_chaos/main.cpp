//
//  main.cpp
//  new_year_chaos
//
//  Created by Michał Warchalski on 31/03/17.
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

long long NumberOfSwaps(vector<int> Q)
{
    if (Q.size() == 2 or Q.size() == 1)
    {
        return 0;
    }
    
    int size = (int) Q.size();
    long long Swaps = 0;
    
    for (int i = size - 1; i > 1; i--)
    {
        if ( i != Q[i] and i != Q[i-1] and i != Q[i-2])
        {
            return -1;
        }
        
        if (i == Q[i-2])
        {
            swap(Q[i-2], Q[i-1]);
            swap(Q[i-1], Q[i]);
            Swaps += 2;
            continue;
        }
        if (i == Q[i-1])
        {
            swap(Q[i-1], Q[i]);
            Swaps++;
            continue;
        }
        
    }
    
    if (1 == Q[2])
    {
        swap(Q[1], Q[2]);
        Swaps++;
    }
    
    return Swaps;
}


int main(){
    int T;
    cin >> T;
    for(int a0 = 0; a0 < T; a0++)
    {
        int n;
        cin >> n;
        vector<int> q(n+1);
        
        for(int q_i = 1; q_i < n+1; q_i++)
        {
            cin >> q[q_i];
        }
        long long answer = NumberOfSwaps(q);
        
        if (answer == -1)
        {
            cout<<"Too chaotic"<<endl;
        }
        else cout << answer << endl;

        
    }
    
    
    
    
    
    
    
    
    return 0;
}

