//
//  main.cpp
//  longest_increasing_subsequence
//
//  Created by Michał Warchalski on 20/05/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int const MAX = 1e6 + 10;
int const INF = 1e6;
int N;
vector<int> A(MAX);
vector<int> Smallest(MAX, INF); //Smallest[Len] is the smallest integer ending a subsequence of length Len
long MaxLength = 1;
long Length;

void LIS()
{
    Smallest[1] = A[0];
    
    for (int i = 1; i < N; i++)
    {
        auto aux = lower_bound(Smallest.begin() + 1, Smallest.end(), A[i]);
        Length = aux - Smallest.begin();
        Smallest[Length] = min(Smallest[Length], A[i]);
        MaxLength = max(MaxLength, Length);
    }
}

int main(int argc, const char * argv[])
{
//    freopen("/Users/Waral/Documents/Coding/Algorithms and Data structures/longest_increasing_subsequence/test.txt", "r", stdin);
//    freopen("/Users/Waral/Documents/Coding/Algorithms and Data structures/longest_increasing_subsequence/testout.txt", "w", stdout);
    
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    
    LIS();
    
    cout << MaxLength << endl;
    
    return 0;
}
