//
//  main.cpp
//  equations
//
//  Created by Michał Warchalski on 30/04/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
long long const Mod = 1000007;

//long long const SIZE = 1000000;
//vector<long long> FactorMultipli(SIZE);

bool IfPrime(long long n)
{
    if (n == 2)
    {
        return true;
    }
    
    if (n == 3)
    {
        return true;
    }
    
    for (long long i = 2; i < sqrt(n) + 1; i++)
    {
        if ((n % i) == 0)
        {
            return false;
        }
    }
    
    return true;
}

long long MultiplicityInFactorial(long long p, long long n)
{
    long long result = 0;
    long long k = p;
    
    while ( (n / k) > 0)
    {
        result = (result + (n / k)) % Mod;
        //cout <<"k: "<< k<<" n/k: "<< n/k << endl;
        k *= p;
    }
    
    return result;
}

long long Solutions(long long n)
{
    vector<long long> FactorsMulti;
    FactorsMulti.reserve(n);
    long long answer = 1;
    
    for (long long i = 2; i < n + 1; i++)
    {
        if (IfPrime(i))
        {
            long long multi = (2 * MultiplicityInFactorial(i, n)) % Mod;
            FactorsMulti.push_back(multi);
            //cout << i <<" has multiplicity " << multi << endl;
        }
    }
    
    long long size = FactorsMulti.size();
    
    for (long long i = 0; i < size; i++)
    {
        answer = (answer * (FactorsMulti[i] + 1)) % Mod;
    }

    return answer;
}

int main(int argc, const char * argv[]) {
    
    long long n;
    
    cin >> n;
    
    cout << Solutions(n) << endl;
    
    
    return 0;
}
