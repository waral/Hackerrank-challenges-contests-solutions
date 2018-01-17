//
//  main.cpp
//  maximum_subarray
//
//  Created by Michał Warchalski on 15/05/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int const MAXSIZE = 123456;
int const MAXVAL = 12345;
vector<int> MaxSumStart(MAXSIZE, -MAXVAL);
vector<int> MaxSumUntil(MAXSIZE, -MAXVAL);
vector<int> A(MAXSIZE);

void Cont(int N)
{
    MaxSumStart[N-1] = A[N-1];
    MaxSumUntil[N-1] = A[N-1];
    
    for (int i = N - 2; i > -1; i--)
    {
        int CheckSum = A[i] + MaxSumStart[i+1];
        
        MaxSumStart[i] = max(CheckSum, A[i]);
        
        MaxSumUntil[i] = max(MaxSumStart[i], MaxSumUntil[i+1]);
    }
    
}

int NonCont(int N)
{
    sort(A.begin(), A.begin()+N);
    
    if (A[N-1] <= 0)
    {
        return A[N-1];
    }
    
    int Answer = 0;
    
    for (int i = 0; i < N; i++)
    {
        if (A[i] > 0)
        {
            Answer += A[i];
        }
    }
    
    return Answer;
}

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    vector<pair<int, int>> Answer(T);
    
    for (int t = 0; t < T; t++)
    {
        int N;
        cin >> N;
        
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Cont(N);
        Answer[t].first = MaxSumUntil[0];
        Answer[t].second= NonCont(N);
    }
    
    for (int t = 0; t < T; t++)
    {
        cout << Answer[t].first <<" "<< Answer[t].second << endl;
    }
    

    return 0;
}
