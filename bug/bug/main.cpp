//
//  main.cpp
//  bug
//
//  Created by Michał Warchalski on 05/05/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <list>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int grid_i = 0; grid_i < n; grid_i++){
        cin >> grid[grid_i];
    }
    
    for( int i = 0; i < n; i++)
    {
        for( int j = 0; j < n; j++)
        {
            if( grid[i][j] == 'X') cout << i <<","<<j <<endl;
        }
    }
    
    
    
    return 0;
}
