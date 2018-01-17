//
//  main.cpp
//  missing_numbers
//
//  Created by Michał Warchalski on 15/05/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 12345;
vector<int> AppA(MAX, 0);
vector<int> AppB(MAX, 0);

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    //vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        AppA[a]++;
    }
    
    int m;
    cin >> m;
    //vector<int> b(m);
    for (int i = 0; i < m; i++)
    {
        int b;
        cin >> b;
        AppB[b]++;
    }
    
    for (int i = 0; i < MAX; i++)
    {
        if (AppB[i] > AppA[i])
        {
            cout << i <<" ";
        }
    }

    return 0;
}
