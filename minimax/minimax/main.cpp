//
//  main.cpp
//  minimax
//
//  Created by Michał Warchalski on 24/04/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int FirstNonzero(long long a)
{
    int answer = 0;
    
    while (a > 0)
    {
        answer++;
        
        a >>= 1;
    }
    
    return answer;
}

long long FindMinimax(vector<long long> a)
{
    long long n = a.size();
    long long max = 1;
    long long temp;
    long long min;
    int FNonzero;
    
    while (max > 0)
    {
        max = a[1];
        min = a[1];
        
        for(int i = 0; i < n; i++)
        {
            if (a[i] > max)
            {
                max = a[i];
            }
            
            if (a[i] < min)
            {
                min = a[i];
            }
        }
        
        if (max == 0)
        {
            return 0;
        }
        
        FNonzero = FirstNonzero(max);
        
        if (FNonzero == FirstNonzero(min))
        {
            //cout <<"FirstNonzero: "<< FirstNonzero(max) << endl;
            temp = (1 << (FirstNonzero(max) - 1));
            
            for (int i = 0; i < n; i++)
            {
                a[i] -= temp;
            }
        }
        else break;
        
    }
    
    vector <long long> Smaller;
    vector <long long> Bigger;
    
    
    for (int i = 0; i < n; i++)
    {
        if (FNonzero == FirstNonzero(a[i]))
        {
            Bigger.push_back(a[i]);
        }
        
        else
        {
            Smaller.push_back(a[i]);
        }
    }
    
    long long SizeBigger = Bigger.size();
    long long SizeSmaller = Smaller.size();
    long long Answer = 2*max;
    
    for (int i = 0; i < SizeBigger; i++)
    {
        for (int j = 0; j < SizeSmaller; j++)
        {
            temp = Bigger[i]^Smaller[j];
            
            if (temp < Answer)
            {
                Answer = temp;
            }
        }
    }

    return Answer;
}


int main() {
    
    int n;
    
    cin >> n;
    
    vector<long long> a(n);
    
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    cout << FindMinimax(a) << endl;
    
    
    
    return 0;
}
