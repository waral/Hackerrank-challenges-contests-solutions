//
//  main.cpp
//  string_reduction
//
//  Created by Michał Warchalski on 28/04/17.
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
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int stringReduction(string s)
{
    
    int aNumber = 0, bNumber = 0, cNumber = 0;
    int size = (int)s.size();
    
    if(size == 0)
    {
        return 0;
    }
    
    for (int i = 0; i < size; i++)
    {
        if (s[i] == 'a')
        {
            aNumber++;
        }
        if (s[i] == 'b')
        {
            bNumber++;
        }
        if (s[i] == 'c')
        {
            cNumber++;
        }
    }
    
    if ( (aNumber == 0 and bNumber == 0) or (bNumber == 0 and cNumber == 0) or (aNumber == 0 and cNumber == 0) )
    {
        return size;
    }
    
    if ( (aNumber - bNumber) % 2 == 0 and (bNumber - cNumber) % 2 == 0)
    {
        return 2;
    }
    
    return 1;
}

int main() {
    int res, t, i;
    scanf("%d",&t);
    
    for (i=0;i<t;i++)
    {
        string s;
        cin >> s;
        res=stringReduction(s);
        printf("%d\n",res);
    }
    
    
  
    return 0;
}
