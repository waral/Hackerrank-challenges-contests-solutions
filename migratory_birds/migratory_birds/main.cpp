//
//  main.cpp
//  migratory_birds
//
//  Created by Michał Warchalski on 29/04/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    long long  n;
    cin >> n;
    
    vector<int> types(n);
    
    for(long long types_i = 0; types_i < n; types_i++)
    {
        cin >> types[types_i];
    }
    
    sort(types.begin(), types.end());
    
    int MaxIndex = 0;
    long long MaxNumber = 0;
    long long CurrentNumber = 0;
    int CurrentType = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (types[i] != CurrentType)
        {
            if (CurrentNumber > MaxNumber)
            {
                MaxNumber = CurrentNumber;
                MaxIndex = CurrentType;
            }
            CurrentNumber = 1;
            CurrentType = types[i];
        }
        else CurrentNumber++;
        
        if (types[i] == 5 and CurrentNumber > MaxNumber)
        {
            MaxIndex = 5;
            break;
        }
    }
    
    
    cout << MaxIndex << endl;
    
    
    
    return 0;
}