//
//  main.cpp
//  largest_rectangle
//
//  Created by Michał Warchalski on 04/04/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main(int argc, const char * argv[]) {
    
    long long MaxArea = 0;
    int N;
    
    cin >> N;

    
    long long h[N+1];
    int PreviousTaller[N+1];
    
    for (int i = 0; i < N+1; i++)
    {
        PreviousTaller[i] = 1;
    }
    
    stack<int> Buildings;
    
    for (int i = 0; i < N + 1; i++)
    {
        if (i < N)
        {
            cin >> h[i];
        }
        else h[i] = 0;

        while (!Buildings.empty() and h[Buildings.top()] >= h[i])
        {
            int       CurrentBuildingNumber = Buildings.top();
            long long CurrentBuilding       = h[CurrentBuildingNumber];
            long long CurrentArea           = (PreviousTaller[i] - 1 + PreviousTaller[CurrentBuildingNumber])*CurrentBuilding;
            
           // cout<<"on the top "<<CurrentBuilding<<endl;
            MaxArea = max(CurrentArea, MaxArea);
           // cout<<"MaxArea = "<<MaxArea<<endl;
            Buildings.pop();
            PreviousTaller[i] += PreviousTaller[CurrentBuildingNumber];
        }
        
        //cout<<"PreviousTaller["<<i<<"] = "<< PreviousTaller[i] << endl;
        
        if (!Buildings.empty())
        {
            long long CurrentBuilding = h[Buildings.top()];
            
           // cout<<"if on the top "<<CurrentBuilding<<endl;
            MaxArea =  max((PreviousTaller[i] + PreviousTaller[Buildings.top()])*CurrentBuilding, MaxArea);
           // cout<<"If: MaxArea = "<<MaxArea<<endl;
        }
        
        Buildings.push(i);
    }
    
    
    cout << MaxArea << endl;
    
    
    
    
    return 0;
}
