//
//  main.cpp
//  knightL
//
//  Created by Michał Warchalski on 30/04/17.
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

int KnightL(int a, int b, int n)
{
    list<pair<pair<int, int>, int>> ToVisit;
    
    vector<vector<bool>> visited(n);
    
    for (int i = 0; i < n; i++)
    {
        visited[i].resize(n);
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = false;
        }
    }
    
    //int distance = 0;
    
    ToVisit.push_back({{0, 0}, 0});
    
    while (!ToVisit.empty())
    {
        auto top = ToVisit.front();
        int u = top.first.first;
        int v = top.first.second;
        int dist = top.second;
        ToVisit.pop_front();
        
        if (u == n-1 and v == n-1)
        {
            return dist;
        }
        
        if (visited[u][v])
        {
            //cout << "visited" << endl;
            continue;
        }
        
        visited[u][v] = true;

        
        dist++;
        
        for (int i = -1; i < 2; i++)
        {
            for (int j = -1; j < 2; j++)
            {
                
                if (i != 0 and j!= 0)
                {
                    if ( u+ i*a < n and u + i*a > -1 and v + j*b < n and v + j*b > -1)
                    {
                        //cout << "adding "<< u + i*a <<" "<< v + j*b << endl;
                        
                        ToVisit.push_back({{u + i*a, v + j*b}, dist});
                    }

                }
                
            }
        }
        
        for (int i = -1; i < 2; i++)
        {
            for (int j = -1; j < 2; j++)
            {
                
                if (i != 0 and j!= 0)
                {
                    if (u + i*b < n and u + i*b > -1 and v + j*a < n and v + j*a > -1)
                    {
                        //cout << "adding "<< u + i*b <<" "<< v + j*a << endl;
                        ToVisit.push_back({{u + i*b, v + j*a}, dist});
                    }

                }
                
            }
        }

    }
    
    return -1;
}

int main()
{
    int n;
    cin >> n;
    
    vector<vector<int>> ans(n);
    
    for (int i = 0; i < n; i++)
    {
        ans[i].resize(n);
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            //ans[i][j] = KnightL(i, j, n);
            cout << KnightL(i, j, n)<<" ";
        }
        cout << endl;
    }
    
//    for (int i = 1; i < n; i++)
//    {
//        for (int j = 1; j < n; j++)
//        {
//            cout << ans[i][j] << " ";
//        }
//        cout << endl;
//    }
    
    return 0;
}
