//
//  main.cpp
//  x_shots_correct
//
//  Created by Michał Warchalski on 15/04/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    long N, M;
    long long ans = 0;
    cin >> N >> M;
    
    vector<long long> A(N), B(N);
    
    for (int i = 0; i < N; i++)
    {
        cin>> A[i] >> B[i];
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    ans = N*M;
    
    for (int i = 0; i < M; i++)
    {
        int C, D;
        
        cin >> C >> D;
        
        ans -= (A.end() - upper_bound(A.begin(), A.end(), D));
        ans -= (lower_bound(B.begin(), B.end(), C) - B.begin());
    }
    
    cout << ans << endl;
    
    
    return 0;
}
