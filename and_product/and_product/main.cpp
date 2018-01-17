//
//  main.cpp
//  and_product
//
//  Created by Michał Warchalski on 26/04/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int FirstNonzero(long long a)
{
    int answer = 0;
    
    while (a > 0)
    {
        answer++;
        
        a >>= 1;
    }
    
    return answer;
}

vector<int> BinaryDecomp(long long a)
{
    int size = FirstNonzero(a);
    vector<int> Decomp(size,0);
    
    for (int i = 0; i < size; i++)
    {
        if(a & 1)
        {
            Decomp[i] = 1;
        }
        //cout << Decomp[i]<< " ";
        a >>= 1;
    }
    //cout << endl;
    
    return Decomp;
}

long long AndProduct (long long a, long long b)
{
    int sizeA = FirstNonzero(a);
    int sizeB = FirstNonzero(b);
    
    if (sizeA < sizeB)
    {
        return 0;
    }
    if (sizeA == 0)
    {
        return 0;
    }
    
    vector<int> DecompA = BinaryDecomp(a);
    vector<int> DecompB = BinaryDecomp(b);
    
    int index = sizeA - 1;
    long long answer = 0;
    
    while ((DecompA[index] == DecompB[index]) and index > -1)
    {
        answer += DecompA[index];
        answer <<= 1;
        index--;
        
    }
    
    if (index > 0)
    {
        answer <<= index;
    }
    
    
    return answer;
}




int main(int argc, const char * argv[])
{
    int n;
    
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        long long a,b;
        
        scanf("%lld %lld", &a, &b);
        
        printf("%lld\n", AndProduct(a, b));

    }
    
    
    //cout << (1 << 2) << endl;
    return 0;
}
