//
//  main.cpp
//  Super_substrings
//
//  Created by Michał Warchalski on 29/03/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;



int main(){
    string s;
    cin >> s;
    
    int size = (int) s.size();
    
    vector< vector<int> > substring; // substring[i][r] is the number of substring beginning with i-th character, even
                                    // and such that the sum of digits = r mod 3
    substring.resize(size + 1);
    
    for (int i = 0; i < size + 1; i++)
    {
        substring[i].resize(3);
    }
    
    long long ans = substring[size - 1][0];
    
    for (int i = size - 1; i > - 1; i--)
    {
        if ( (s[i] - '0') % 6 == 0 )
        {
            substring[i][0] = substring[i+1][0] + 1;
            substring[i][1] = substring[i+1][1];
            substring[i][2] = substring[i+1][2];
        }
        
        if ( (s[i] - '0') % 6 == 1 )
        {
            substring[i][0] = substring[i+1][2];
            substring[i][1] = substring[i+1][0];
            substring[i][2] = substring[i+1][1];
        }

        if ( (s[i] - '0') % 6 == 2 )
        {
            substring[i][0] = substring[i+1][1];
            substring[i][1] = substring[i+1][2];
            substring[i][2] = substring[i+1][0] + 1;
        }
        
        if ( (s[i] - '0') % 6 == 3 )
        {
            substring[i][0] = substring[i+1][0];
            substring[i][1] = substring[i+1][1];
            substring[i][2] = substring[i+1][2];
        }
        
        if ( (s[i] - '0') % 6 == 4 )
        {
            substring[i][0] = substring[i+1][2];
            substring[i][1] = substring[i+1][0] + 1;
            substring[i][2] = substring[i+1][1];
        }
        
        if ( (s[i] - '0') % 6 == 5 )
        {
            substring[i][0] = substring[i+1][1];
            substring[i][1] = substring[i+1][2];
            substring[i][2] = substring[i+1][0];
        }
        
        if (s[i] != '0')
        {
            ans = ans + substring[i][0];
           // cout<< "increasing answer by "<<substring[i][0] << " character "<<s[i]<<endl;
        }
        else
        {
            ans++;
           // cout<< "increasing answer by 1 character "<<s[i]<<endl;
        }
        

    }
    
    cout << ans << endl;
    
    return 0;
}