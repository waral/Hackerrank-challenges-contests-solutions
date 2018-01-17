//
//  main.cpp
//  string_similarity
//
//  Created by Michał Warchalski on 27/05/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int const MAXLEN = 100001;
int T;
vector<int> Z(MAXLEN);
string str;
int n;

void getZarr()
{
    n = (int)str.length();
    int L, R, k;
    
    Z[0] = n;
    L = R = 0;
    for (int i = 1; i < n; ++i)
    {
        if (i > R)
        {
            L = R = i;
            
            while (R<n && str[R-L] == str[R])
                R++;
            Z[i] = R-L;
            R--;
        }
        else
        {
            k = i-L;
            
            if (Z[k] < R-i+1)
                Z[i] = Z[k];
            
            else
            {
                L = i;
                while (R<n && str[R-L] == str[R])
                    R++;
                Z[i] = R-L;
                R--;
            }
        }
    }
}

long GetSumZ()
{
    long Answer = 0;
    
    for (int i = 0; i < n; i++)
    {
        Answer += Z[i];
    }
    
    return Answer;
}

int main(int argc, const char * argv[])
{
    cin >> T;
    
    for (int t = 0; t < T; t++)
    {
        cin >> str;
        getZarr();
        cout << GetSumZ() << endl;
    }
    return 0;
}












