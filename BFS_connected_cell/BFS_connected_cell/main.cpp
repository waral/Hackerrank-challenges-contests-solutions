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

int get_biggest_region(vector< vector<int> > grid, int n, int m)
{
    
    int size_component;
    int max_component=0;
    list <pair<int, int>> to_visit;
    pair <int, int> temp_pair;
    pair <int, int> temp_pair_2;
    
    for(int grid_i = 1 ; grid_i < n+1 ; grid_i++)
    {
        
        
        
        for(int grid_j = 1 ; grid_j < m+1 ; grid_j++)
        {
            
            
            
            if ( grid[ grid_i ][ grid_j ] == 1 )
            {
                
                grid[ grid_i ][ grid_j ] = 0;
                
                size_component=0;
                
                temp_pair.first  = grid_i;
                temp_pair.second = grid_j;
                
                to_visit.push_back(temp_pair);
                
                
                
              //  grid_1=grid_i;
               // grid_2=grid_j;
                
                while ( !to_visit.empty() )
                {
                    
                    size_component++;
                    
                    temp_pair.first  = to_visit.front().first;
                    temp_pair.second = to_visit.front().second;
                    
                    to_visit.pop_front();
                    
                    grid[ temp_pair.first ][ temp_pair.second ] = 0;
                        
                    for (int m = - 1; m < 2; m++)
                    {
                        for (int l = - 1 ; l < 2; l++)
                        {
                            if ( grid[ temp_pair.first + m ][ temp_pair.second + l] == 1)
                            {
                                temp_pair_2.first  = temp_pair.first + m;
                                temp_pair_2.second = temp_pair.second + l;
                                
                                to_visit.push_back(temp_pair_2);
                                
                                //  cout << temp_pair_2.first << " " << temp_pair_2.second << endl;
                                
                                grid[ temp_pair_2.first ][ temp_pair_2.second ] = 0;
                            }

                        }
                        
                        
                    }
                    


                }
                
                if (size_component > max_component)
                {
                    max_component=size_component;
                }
                
            }
        
        }
    
    }
    
    
    return max_component;
    
}

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector< vector<int> > grid(n+2,vector<int>(m+2));
    
    for(int grid_i = 0; grid_i < n+2; grid_i++ )
    {
        
        for(int grid_j = 0; grid_j < m+2; grid_j++ )
        {
          
            grid[grid_i][grid_j]=0;
        
        }
    
    }

    
    for(int grid_i = 1; grid_i < n+1 ; grid_i++)
    {
        
        for(int grid_j = 1; grid_j < m+1 ; grid_j++)
        {
        
            cin >> grid[grid_i][grid_j];
        
        }
    
    }
    
    cout << get_biggest_region(grid,n,m) << endl;
   
    return 0;
}
