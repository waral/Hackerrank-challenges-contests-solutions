//
//  main.cpp
//  candies
//
//  Created by Michał Warchalski on 18/06/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int const MAX = 1e5 + 1;
int N;
long long Min;
vector<long long> Rating(MAX, 0);
vector<long long> Decr(MAX, 0);
vector<long long> Incr(MAX, 0);


void Solve()
{
    Incr[0] = 0;
    
    for (int i = 1; i < N; i++)
    {
        if (Rating[i - 1] < Rating[i])
        {
            Incr[i] = Incr[i-1] + 1;
        }
    }
    
    Decr[N-1] = 0;
    
    for (int i = N-2; i > -1; i--)
    {
        if (Rating[i] > Rating[i+1])
        {
            Decr[i] = Decr[i+1] + 1;
        }
    }
    
    for (int i = 0; i < N; i++)
    {
        Min += (max(Decr[i], Incr[i]) + 1);
    }
}

int main(int argc, const char * argv[])
{
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        cin >> Rating[i];
    }
    
    Solve();
    cout << Min << endl;
    
    
    return 0;
}
