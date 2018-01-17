//
//  main.cpp
//  even_odd_boxes
//
//  Created by Michał Warchalski on 20/06/17.
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

long long minimumChocolateMoves(long long n, vector <long long> X)
{
    long long TotalChoc = 0;
    long long OddWrong = 0;
    long long EvenWrong = 0;
    long long EvenIndChoc = 0;
    long long OddIndChoc = 0;
    long long ZeroesEvenInd = 0;
    
    for (int i = 0; i < n; i++)
    {
        TotalChoc += X[i];
        if ( i % 2 == 0)
        {
            EvenIndChoc += X[i];
            if(X[i] % 2 == 0) EvenWrong++;
            
            if (X[i] == 0) ZeroesEvenInd++;
        }
        if ( i % 2 == 1 and X[i] % 2 == 1)
        {
            OddIndChoc += X[i];
            if(X[i] % 2 == 1) OddWrong++;
        }
    }
    
    if ((OddWrong + EvenWrong) % 2 == 1)
    {
        return -1;
    }
    
    if (TotalChoc < n/2 + 1)
    {
        return -1;
    }
    
    //long long parity = 0;
    
//    if (n % 2 == 0) parity = 0;
//    else parity = 1;
//    
//    if (<#condition#>) {
//        <#statements#>
//    }
    
    if (OddWrong >= EvenWrong)
    {
        return EvenWrong + (OddWrong - EvenWrong)/2;
    }
    
    if (ZeroesEvenInd <= OddWrong)
    {
        return OddWrong + (EvenWrong - OddWrong)/2;
    }
    
    if ((EvenWrong - ZeroesEvenInd) % 2 == 0)
    {
        return OddWrong + (EvenWrong - ZeroesEvenInd)/2 + (ZeroesEvenInd - OddWrong);
    }
    
    return OddWrong + (EvenWrong - ZeroesEvenInd + 1)/2 + (ZeroesEvenInd - OddWrong - 1);
    
    //return 0;
}

int main() {
    //  Return the minimum number of chocolates that need to be moved, or -1 if it's impossible.
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        long long n;
        cin >> n;
        vector<long long> X(n);
        for(int X_i = 0; X_i < n; X_i++)
        {
            int x;
            cin >> x;
            X[X_i] = x - 1;
        }
        long long result = minimumChocolateMoves(n, X);
        cout << result << endl;
    }
    return 0;
}