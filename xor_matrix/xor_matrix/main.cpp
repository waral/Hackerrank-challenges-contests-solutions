//
//  main.cpp
//  xor_matrix
//
//  Created by Michał Warchalski on 23/04/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    long long n, m;
    
    cin >> n >> m;
    
    vector<long long> a(n);
    vector<long long> b(n);
    
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    
    int count = 1;
    
    m--;
    
    while (m > 0)
    {
        if ( m % 2 == 1)
        {
            for (int i = 0; i < n; i++)
            {
                b[i] = a[i] ^ a[(i+count) % n];
            }
            
            for (int i = 0; i < n; i++)
            {
                a[i] = b[i];
            }
        }
        
        count = (count * 2) % n;
        
        m >>= 1;
    }
    
    for (int i = 0; i < n; i++)
    {
        cout<< a[i] <<" ";
    }
    
//    int k = 2 << 1; =4
//    cout<< k << endl;
    
    
    return 0;
}
