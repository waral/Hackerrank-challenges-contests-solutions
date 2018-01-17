//
//  main.cpp
//  mixing_proteins
//
//  Created by Michał Warchalski on 24/04/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

char mult(char X, char Y)
{
    if ( X == 'A')
    {
        return Y;
    }
    
    if (Y == 'A')
    {
        return X;
    }
    
    if (X == Y)
    {
        return 'A';
    }
    
    if ((X == 'B' and Y == 'C') or (X == 'C' and Y == 'B'))
    {
        return 'D';
    }
    
    if ((X == 'C' and Y == 'D') or (X == 'D' and Y == 'C'))
    {
        return 'B';
    }
    
    if ((X == 'B' and Y == 'D') or (X == 'D' and Y == 'B'))
    {
        return 'C';
    }

    cout<<"no!"<<endl;
    return 0;
    
}

int main(int argc, const char * argv[])
{
    
    long long n, m;
    
    cin >> n >> m;
    
    vector<char> a(n);
    vector<char> b(n);
    
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    
    int count = 1;
    
    //m--;
    
    while (m > 0)
    {
        if ( m % 2 == 1)
        {
            for (int i = 0; i < n; i++)
            {
                b[i] = mult(a[i], a[(i+count) % n]);
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
        cout<< a[i];
    }
    
    cout<<endl;
    
    //    int k = 2 << 1; =4
    //    cout<< k << endl;
    
    
    return 0;
}
