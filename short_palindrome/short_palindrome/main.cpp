//
//  main.cpp
//  short_palindrome
//
//  Created by Michał Warchalski on 04/05/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long const Mod = 1000000007;

int main(int argc, const char * argv[])
{
    string s;
    
    cin >> s;
    
    vector<vector<long long>> Suffix(26, vector<long long> (26, 0));
    vector<long long> Letters(26, 0);
    vector<long long> Letters2(26, 0);
    long long Answer = 0;
    
    for (char& c : s)
    {
        
        for (int j = 0; j < 26; j++)
        {
            Suffix[j][c - 'a'] = (Suffix[j][c - 'a'] + Letters[j]) % Mod;
            //char k = 'a' + j;
            
//            if (Letters[j] != 0)
//            {
//                cout << "Suffix " <<k <<" "<< c <<" "<< Suffix[j][c - 'a'] << endl;
//            }
            
        }
        
        Letters[c - 'a']++;
        
    }
    
    for (char& c : s)
    {
        Letters[c - 'a'] --;
        
        for (int j = 0; j < 26; j++)
        {
            Suffix[c - 'a'][j] = (Suffix[c - 'a'][j] - Letters[j] + Mod) % Mod;
            Answer = (Answer + (Letters2[j]*Suffix[c - 'a'][j]) % Mod) % Mod;
            
            //char k = 'a'+j;
            
            //if(Letters2[j] > 0) cout<< "Letters until now "<< k << " " << Letters2[j] << endl;
            
            //cout << " Answer " <<  Answer << endl;
        }
        
        Letters2[c - 'a']++;
        
    }
    
    cout << Answer << endl;
    
    
    
    
    return 0;
}
