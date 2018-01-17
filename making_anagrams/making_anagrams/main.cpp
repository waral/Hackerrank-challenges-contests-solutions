//
//  main.cpp
//  making_anagrams
//
//  Created by Michał Warchalski on 03/05/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main()
{
    string s1, s2;
    vector<int> letters1(26, 0), letters2(26, 0);
    int answer = 0;
    
    cin >> s1 >> s2;
    
    int size1 = (int)s1.size(), size2 = (int)s2.size();
    
    for (int i = 0 ; i < size1; i++)
    {
        letters1[s1[i] - 'a']++;
    }
    
    for (int i = 0 ; i < size2; i++)
    {
        letters2[s2[i] - 'a']++;
    }
    
    for (int i = 0; i < 26; i++)
    {
        answer += abs(letters1[i] - letters2[i]);
    }
    
    cout << answer << endl;

    
    return 0;
}