//
//  main.cpp
//  lucky_numbers
//
//  Created by Michał Warchalski on 30/05/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

int T;
string A, B;
int Primes = 0;
long long LuckyB = 0;

vector<bool> Prime(1600, true);
long long DP[20][190][1600];

void GetPrimes()
{
    
    for (int n = 2; n < 1600; n++)
    {
        for (int i = 2; i < sqrt(n) + 1; i++)
        {
            if (n % i == 0)
            {
                Prime[n] = false;
                break;
            }
        }
    }
    
    Prime[0] = false;
    Prime[1] = false;
    Prime[2] = true;
    
}

void Fill()
{
    for (int s1 = 0; s1 < 190; s1++)
    {
        for (int s2 = 0; s2 < 1600; s2++)
        {
            if (Prime[s1] and Prime[s2])
            {
                DP[0][s1][s2] = 1;
            }
            else DP[0][s1][s2] = 0;
        }
    }
    
    for (int d = 1; d < 20; d++)
    {
        for (int s1 = 0 ; s1 < (19 - d)*9; s1++)
        {
            for (int s2 = 0; s2 < (19-d)*81; s2++)
            {
                for (int i = 0; i < 10; i++)
                {
                    DP[d][s1][s2] += DP[d-1][s1+i][s2+i*i];
                }
            }
        }
    }
    
    
}

long long Lucky(string Num)
{
    int n = (int)Num.length();
    int SumDig = 0;
    int SumDigSq = 0;
    long long Answer = 0;
    LuckyB = 0;
    
    for (int d = 0; d < n; d++)
    {
        for (int j = 0; j < Num[d] - '0'; j++)
        {
            Answer += DP[n - 1 - d][ SumDig + j ][ SumDigSq+ (j*j) ];
        }
        SumDig += (Num[d] - '0');
        SumDigSq += (Num[d] - '0')*(Num[d] - '0');
    }
    
    LuckyB += DP[0][SumDig][SumDigSq];
    
    return Answer;
}

int main(int argc, const char * argv[])
{
    GetPrimes();
    Fill();

    cin >> T;
    
    while (T--)
    {
        cin >> A >> B;
        cout << Lucky(B) + LuckyB - Lucky(A) << endl;
        
    }
    
    return 0;
}
