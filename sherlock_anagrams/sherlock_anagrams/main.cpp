//
//  main.cpp
//  sherlock_anagrams
//
//  Created by Michał Warchalski on 25/03/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string sorted[100][100];

void Sort(string s)
{
    
    for (int Length = 1 ; Length < s.length() ; Length++)
    {
        for (int i = 0; i < s.length() - Length + 1; i++)
        {
            string temp = s.substr(i, Length);
            
            sort(temp.begin(), temp.end());
            
            sorted[i][Length] = temp;
            
            //cout << sorted[i][Length] << endl;
        }
    }
}

bool IfAnagrams(string s1, string s2) //works for strings that are already sorted
{
    if (s1.length() != s2.length())
    {
        return false;
    }
    
//    sort(s1.begin(), s1.end());
//    sort(s2.begin(), s2.end());
    
    if (s1.compare(s2))
    {
        return false;
    }

    
    return true;
}

long long NumberPairs(string s)
{
    long long Number=0;
    
    Sort(s);
  
    for (int Length = 1; Length < s.length(); Length++)
    {
        for (int i = 0; i < s.length() - Length + 1; i++)
        {
            for (int j = 0; j < s.length() - Length + 1; j++)
            {
                //cout << s.substr(i, Length) <<" "<< s.substr(j, Length) << endl;
                if (IfAnagrams(sorted[i][Length], sorted[j][Length]) and i != j )
                {
                    //cout << "Entered if" << endl;
                    Number++;
                }
            }
        }
    }
    return Number;
    
}

int main() {
    
    int T;
    cin >> T;
    string s;
    
    long long ans[T];
    
    for (int i = 0 ; i < T ; i++ )
    {
        cin >> s;
        ans[i] = NumberPairs(s)/2;
    }
    
    for (int i = 0; i < T; i++)
    {
        cout << ans[i] << endl;
    }
    
    return 0;
}
