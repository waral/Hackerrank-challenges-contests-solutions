//
//  main.cpp
//  clique
//
//  Created by Michał Warchalski on 08/05/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

long long Turan(long long N, long long R)
{
    
    long long Expr = (N*N - (N % R)*ceil((double)N/(double)R)*ceil((double)N/(double)R) - (R - (N % R))*floor((double)N/(double)R)*floor((double)N/(double)R))/2;
    
    return Expr;
}

long long LowerBoundTuran(long long N, long long M)
{
    long long low , high , mid ;
    low = 1 ;
    high = N ;
    
    while(low <= high)
    {
        mid = ( low + high ) / 2 ; // finding middle element
        
        if(Turan(N, mid) >= M && ( mid == 1 || Turan(N, mid - 1) < M )) // checking conditions for lowerbound
            return mid ;
        
        else if(Turan(N, mid) >= M) // answer should be in left part
            high = mid - 1 ;
        
        else                // answer should in right part if it exists
            low = mid + 1 ;
    }
    
    return mid ; // this will execute when there is no element in the given array which >= K
}


int main(int argc, const char * argv[])
{
    long long T;
    cin >> T;
    
    for (long long i = 0; i < T; i++)
    {
        long long N, M;
        cin >> N >> M;
        cout << LowerBoundTuran(N, M) << endl;

        }
    
    return 0;
}
