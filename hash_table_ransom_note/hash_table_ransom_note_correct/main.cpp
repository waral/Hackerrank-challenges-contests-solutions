//
//  main.cpp
//  hash_table_ransom_note_correct
//
//  Created by Michał Warchalski on 27/03/17.
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
#include <vector>

using namespace std;

unordered_map <string, int> HashTable;

bool ransom_note( vector<string> magazine, vector<string> ransom)
{
    for( auto word : magazine)
    {
        HashTable[word]++;
    }
    
    for (auto word : ransom)
    {
        HashTable[word]--;
        if (HashTable[word] < 0)
        {
            return false;
        }
    }
    
    return true;
}

int main()
{
    int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
        cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
        cin >> ransom[ransom_i];
    }
    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
