//
//  main.cpp
//  Primality
//
//  Created by Michał Warchalski on 20/03/17.
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

bool IfPrime(int n)
{
    if (n==1)
    {
        return false;
    }
    
    if (n==0)
    {
        return false;
    }
    
    if (n==2)
    {
        return true;
    }
    
    for (int i = 2; i < sqrt((double) n) + 1; i++)
    {
        if ( n % i == 0 )
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int p;
    cin >> p;
    vector<bool> ans(p);
    
    for(int i = 0; i < p; i++)
    {
        int n;
        cin >> n;
        ans[i] = IfPrime(n);
    }
    
    for (int i = 0; i < p; i++)
    {
        if (ans[i])
        {
            cout<<"Prime"<<endl;
        }
        else
        {
            cout<<"Not prime"<<endl;
        }
    }
    
    return 0;

}