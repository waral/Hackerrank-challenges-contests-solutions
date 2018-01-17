//
//  main.cpp
//  lilys_homework
//
//  Created by Michał Warchalski on 16/04/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

long long SwapsIncreasing2(vector<long long> a, map<long long, int> A)
{
    long long size = a.size();
    vector<long long> helper(size);
    long long swaps = 0;
    
    for (int i = 0; i < size; i++)
    {
        helper[i] = a[i];
    }
    
    sort(helper.begin(), helper.end(), less<long long>());
    
    for (int i = 0; i < size; i++)
    {
        if (a[i] != helper[i])
        {
            auto it = A.find(helper[i]);
            int found_index = it->second;
            A.erase(a[i]);
            A.erase(helper[i]);
            long long temp = a[i];
            swap(a[i], a[found_index]);
            A.insert({temp, found_index});
            swaps++;
        }
    }
    
    return swaps;
    
    
}

long long SwapsDecreasing2(vector<long long> a, map<long long, int> A)
{
    long long size = a.size();
    vector<long long> helper(size);
    long long swaps = 0;
    
    for (int i = 0; i < size; i++)
    {
        helper[i] = a[i];
    }
    
    sort(helper.begin(), helper.end(), greater<long long>());
    
    for (int i = 0; i < size; i++)
    {
        if (a[i] != helper[i])
        {
            auto it = A.find(helper[i]);
            int found_index = it->second;
            A.erase(a[i]);
            A.erase(helper[i]);
            long long temp = a[i];
            swap(a[i], a[found_index]);
            A.insert({temp, found_index});
            swaps++;
        }
    }
    
    return swaps;
    
    
}

int main(int argc, const char * argv[]) {
    
    int n;
    map<long long , int> A;
    
    scanf("%d", &n);
    
    vector<long long> a(n);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
        A.insert({a[i], i});
    }
    
    cout<<  min(SwapsIncreasing2(a, A), SwapsDecreasing2(a,A)) << endl;
    
    return 0;
}
