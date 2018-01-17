//
//  main.cpp
//  sherlock_and_pairs
//
//  Created by Michał Warchalski on 08/05/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long Pairs(vector<long long> A, int n){
    
    if(n == 1) return 0;
    
    sort(A.begin(), A.end());
    
    long long current=1;
    long long ans = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(i == n-1 or A[i+1] != A[i])
        {
            ans += current*(current - 1);
            //cout << "current "<<current <<endl;
            current = 1;
            continue;
        }
        //cout<<"increasing current" <<endl;
        current++;
    }
    
    return ans;
}

int main()
{
    
    int T;
    cin >> T;
    
    for(int t = 0; t < T; t++)
    {
        int N;
        cin >> N;
        vector<long long> A(N);
        
        for(int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        
        cout << Pairs(A, N) << endl;
    }
    
    return 0;
}