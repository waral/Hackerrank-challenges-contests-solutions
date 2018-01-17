//
//  main.cpp
//  stock_maximize
//
//  Created by Michał Warchalski on 19/06/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int const MAX = 50001;
int T, N;
vector<long long> Price(MAX, 0);
vector<long long> MaxPriceIndex(MAX, 0); // MaxPriceIndex[k] index of max(Price[i]) for i >= k
long long MaxProfit = 0;

void Solve()
{
    long long Max = Price[N-1];
    MaxPriceIndex[N-1] = N-1;
    
    for (int i = N-2; i > -1; i--)
    {
        if (Price[i] >= Max)
        {
            Max = Price[i];
            MaxPriceIndex[i] = i;
        }
        else MaxPriceIndex[i] = MaxPriceIndex[i+1];
    }
    
    
    MaxProfit = 0;
    long long Cost = 0;
    long long StartIndex = 0;
    long long MaxIndex = MaxPriceIndex[0];
    long long k = 0;
    
    while (MaxIndex < N)
    {
        //cout << StartIndex << " " << MaxIndex << endl;
        Cost = 0;
        k = StartIndex;
        while (k < MaxIndex)
        {
            Cost += Price[k];
            k++;
        }
        
        MaxProfit += ((MaxIndex-StartIndex)*Price[MaxIndex] - Cost);
        MaxIndex++;
        StartIndex = MaxIndex;
        
        if (StartIndex >= N) break;
        
        MaxIndex = MaxPriceIndex[MaxIndex];
        
        
    }
    
}

int main(int argc, const char * argv[])
{
    cin >> T;
    
    while (T--)
    {
        cin >> N;
    
        for (int i = 0; i < N; i++)
        {
            cin >> Price[i];
        }
        
        Solve();
        cout << MaxProfit << endl;
    }
    return 0;
}
