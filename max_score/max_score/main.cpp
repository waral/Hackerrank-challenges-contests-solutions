//
//  main.cpp
//  max_score
//
//  Created by Michał Warchalski on 05/05/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//



#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <list>
#include <string>

using namespace std;

long long const NUMBER = (1 << 20);
int Bin[NUMBER][20];
long long Score[NUMBER];
bool Considered[NUMBER];
long long RS[NUMBER];
//vector<int> A(20);

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


void Binary(int n)
{
    long long num = (1 << n);
    
    for (long long i = 0; i < num; i++)
    {
        vector<int> decomp = BinaryDecomp(i);
        int size = (int)decomp.size();
        
        for (int j = 0; j < size; j++)
        {
            Bin[i][j] = decomp[j];
        }
    }
}

void RunningSum( vector<long long> a , int n)
{
    long long num = (1 << n);
    
    for (long long i = 0; i < num; i++)
    {
        long long b = i^(num - 1);
        long long Running = 0;
        
        for (int j = 0; j < 20; j++)
        {
            if(Bin[b][j] == 1)
            {
                Running += a[j];
            }
        }
        
        RS[i] = Running;
    }
}

long long MaxScore(long long A, vector<long long> a)
{
    if (Considered[A])
    {
        return Score[A];
    }
    
    Considered[A] = true;
    
    long long Max = 0;
    long long Temp = 0;
    
    for (int i = 0; i < 20; i++)
    {
        if (Bin[A][i] == 1)
        {
            Temp =  (RS[A - (1 << i)] % a[i]) + MaxScore(A - (1 << i), a);
            
            if (Temp > Max)
            {
                Max = Temp;
            }
        }
    }
    
    Score[A] = Max;
    
    return Score[A];
    
}

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    vector<long long> a(n);
    
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    Binary(n);
    
    long long num = (1 << n);
    
    for (long long i = 0; i < num; i++)
    {
        Considered[i] = false;
    }

    RunningSum(a, n);
    
    
    cout<< MaxScore((1 << n) - 1, a) << endl;
    
    
    return 0;
}
