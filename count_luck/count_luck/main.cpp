//
//  main.cpp
//  count_luck
//
//  Created by Michał Warchalski on 07/04/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

//
//  main.cpp
//  BFS_connected_cell
//
//  Created by Michał Warchalski on 18/03/17.
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

int Wave(vector< vector<char> > grid, int Start_i, int Start_j)
{
    
    int WaveTimes=0;
    bool found = false;
    int size1 = grid.size();
    
    list <pair<int, int>> to_visit;
    pair <int, int> temp_pair;
    pair <int, int> temp_pair_2;
    vector<vector<int>> waves;
    
    waves.resize(size1);
    
    int size2 = grid[0].size();
    
    for (int i = 0; i < size1; i++)
    {
        waves[i].resize(size2);
    }
    
    
                
                temp_pair.first  = Start_i;
                temp_pair.second = Start_j;
                
                to_visit.push_back(temp_pair);
                
                
                
                //  grid_1=grid_i;
                // grid_2=grid_j;
                
                while ( !to_visit.empty() )
                {
                    
                    temp_pair.first  = to_visit.front().first;
                    temp_pair.second = to_visit.front().second;
                    
                    to_visit.pop_front();
                    
                    grid[ temp_pair.first ][ temp_pair.second ] = 'X';
                    
                    int count = 0;
                    
                    for (int m = -1; m < 2; m++)
                    {
                        for (int l = -1; l < 2; l++)
                        {
                            if ( (m == -1 and l == 0 ) or ( m == 1 and l == 0) or ( m == 0 and l == -1) or ( m == 0 and l == 1))
                            {
                                if ( grid[ temp_pair.first + m ][ temp_pair.second + l] == '.')
                                {
                                    count++;
                                    temp_pair_2.first  = temp_pair.first + m;
                                    temp_pair_2.second = temp_pair.second + l;
                                    
                                    to_visit.push_back(temp_pair_2);
                                    
                                    //  cout << temp_pair_2.first << " " << temp_pair_2.second << endl;
                                    
                                    grid[ temp_pair_2.first ][ temp_pair_2.second ] = 'X';
                                }
                                
                                if (grid[ temp_pair.first + m ][ temp_pair.second + l] == '*')
                                {
                                    WaveTimes = waves[ temp_pair.first][ temp_pair.second];
                                    count++;
                                    found = true;
                                }


                            }
                            
                            
                        }
                    }

                    
                    if (found == true and count > 1)
                    {
                        return WaveTimes + 1;
                    }
                    
                    if (found == true)
                    {
                        return WaveTimes;
                    }
                    
                    
                        for (int m = - 1; m < 2; m++)
                        {
                            for (int l = - 1 ; l < 2; l++)
                            {
                                if ( (m == -1 and l == 0 ) or ( m == 1 and l == 0) or ( m == 0 and l == -1) or ( m == 0 and l == 1))
                                {
                                    if (count > 1)
                                    {
                                    
                                        waves[ temp_pair.first + m ][ temp_pair.second + l] = waves[ temp_pair.first][ temp_pair.second] + 1;
                                    }
                                    
                                    else waves[ temp_pair.first + m ][ temp_pair.second + l] = waves[ temp_pair.first][ temp_pair.second];
                                
                                }
                            }
                        }

                }
                    
    
    return 0;
    
}

int main()
{
    int T;
    int start_i = 0, start_j=0;
    
    cin >> T;
    
    
    for (int q = 0; q < T; q++)
    {
        int n;
        
        cin >> n;
        
        int m;
        
        cin >> m;
        
        vector< vector<char> > grid(n+2,vector<char>(m+2));
        
        for(int grid_i = 0; grid_i < n+2; grid_i++ )
        {
            
            for(int grid_j = 0; grid_j < m+2; grid_j++ )
            {
                
                grid[grid_i][grid_j] = 'X';
                
            }
            
        }
        
        for (int grid_i = 1; grid_i < n+1; grid_i++)
        {
            string s;
            cin >> s;
            int grid_j = 1;
            
            for (char &c: s)
            {
                grid[grid_i][grid_j] = c;
                
                if (c == 'M')
                {
                    start_i = grid_i;
                    start_j = grid_j;
                }
                
                grid_j++;
                
            }
        }
        
        int K;
        
        cin >> K;
        
        int ans = Wave(grid,start_i,start_j);
        
        if (ans == K)
        {
            cout << "Impressed" <<endl;
        }
        else cout << "Oops!" << endl;
    }
    
    
    return 0;
}

