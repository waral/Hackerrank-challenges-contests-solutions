//
//  main.cpp
//  max_min_difference
//
//  Created by Michał Warchalski on 29/03/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

using namespace std;
#include<iostream>
#include<set>
#include<vector>

long long Diff(multiset<long long> S)
{
    if (S.empty())
    {
        return 0;
    }
    
    return (*S.rbegin()) - (*S.begin());
}

int Correction(long long N, long long diff)
{
    if (diff > N)
    {
        return - 1;
    }
    return 0;
}

long long DifferenceSmaller(long long High, long long Low, vector<int> a)
{
    multiset<long long> SortedHigh, SortedLow;
    int Size = (int) a.size();
    long long ans = 0;
    int RightIndexHigh = 0, RightIndexLow = 0;
    long long diffHigh;
    long long diffLow;
    
    for (int i = 0; i < Size; i++)
    {
        diffHigh = Diff(SortedHigh);
        diffLow = Diff(SortedLow);
        while (RightIndexHigh < Size and diffHigh <= High)
        {
            
            SortedHigh.insert(a[RightIndexHigh++]);
            
           // RightIndexHigh++;
            
            diffHigh = Diff(SortedHigh);
            
            // cout<<RightIndex<<endl;
            
        }
        
        while (RightIndexLow < Size and diffLow <= Low - 1)
        {
            
            SortedLow.insert(a[RightIndexLow++]);
            
           // RightIndexLow++;
            
            diffLow = Diff(SortedLow);
            
            // cout<<RightIndex<<endl;
            
        }
        
        
        
        ans += RightIndexHigh - RightIndexLow + Correction(High, diffHigh) - Correction(Low - 1, diffLow);
        
        
        
        SortedHigh.erase(SortedHigh.find(a[i]));
        SortedLow.erase(SortedLow.find(a[i]));// updating the sorted set of values
    }
    
    return ans;
}

int main(){
    int n;
    int q;
    
    scanf("%d %d", &n, &q);
    
    vector<int> a(n);
    
    for(int a_i = 0; a_i < n; a_i++)
    {
        scanf("%d", &a[a_i]);
    }
    
    long long answer;
    
    for(int a0 = 0; a0 < q; a0++)
    {
        long long low;
        long long high;
        
        scanf("%lld %lld", &low, &high);
        
        answer = DifferenceSmaller(high, low, a);
        
        printf("%lld\n", answer);
    }
    
    
    return 0;
}
