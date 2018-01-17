//
//  main.cpp
//  chocolate_fiesta
//
//  Created by Michał Warchalski on 25/05/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

long long const MOD = 1e9 + 7;

long long Answer = 0;
long long EvenSum = 0;
long long OddSum = 0;
int const MAXSIZE = 123456;
int N;
vector<int> A(MAXSIZE);
long long OldEvenSum = 0, OldOddSum = 0;



void Solve()
{
    for (int i = 0; i < N; i++)
    {
        OldEvenSum = EvenSum;
        OldOddSum = OddSum;
        //cout << EvenSum << " " << OddSum << endl;
        if (A[i] % 2 == 0)
        {
            Answer +=  (OldEvenSum + 1);
            EvenSum+=  (OldEvenSum + 1);
            OddSum +=   OldOddSum;
        }
        else
        {
            Answer += OldOddSum;
            EvenSum += OldOddSum;
            OddSum += (OldEvenSum + 1);
        }
        Answer = Answer % MOD;
        EvenSum = EvenSum % MOD;
        OddSum = OddSum % MOD;
    }
}

int main(int argc, const char * argv[])
{
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    
    Solve();
    cout << Answer << endl;
    return 0;
}
