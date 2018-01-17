//
//  main.cpp
//  bit_manipulation_lonely_integer
//
//  Created by Michał Warchalski on 24/03/17.
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

//int lonely_integer(vector < int > a) {
//    return 0;
//}

int main(){
    int n;
    int a;
    
    cin >> n;
    //vector<int> a(n);
    int ans=0;
    for(int a_i = 0;a_i < n;a_i++)
    {
        cin >> a;
        ans=ans^a;
    }
    
    
    cout << ans << endl;
    return 0;
}

