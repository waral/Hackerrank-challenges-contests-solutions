//
//  main.cpp
//  who_catches
//
//  Created by Michał Warchalski on 02/06/17.
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

int whoGetsTheCatch(int n, int x, vector < int > X, vector < int > V){
    
    if (n == 1)
    {
        return 0;
    }
    
    vector<pair<int, int>> Time(n);
    
    for(int i = 0; i < n ; i++){
        Time[i].first = abs(x - X[i])/V[i];
        Time[i].second = i;
    }
    
    sort(Time.begin(), Time.end());
    
    if (Time[0].first == Time[1].first)
    {
        return -1;
    }
    
    
    return Time[0].second;
    
    
}

int main() {
    //  Return the index of the catcher who gets the catch, or -1 if no one gets the catch.
    int n;
    int x;
    cin >> n >> x;
    vector<int> X(n);
    for(int X_i = 0; X_i < n; X_i++){
        cin >> X[X_i];
    }
    vector<int> V(n);
    for(int V_i = 0; V_i < n; V_i++){
        cin >> V[V_i];
    }
    int result = whoGetsTheCatch(n, x, X, V);
    cout << result << endl;
    return 0;
}
