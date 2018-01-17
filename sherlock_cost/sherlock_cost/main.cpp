//
//  main.cpp
//  sherlock_cost
//
//  Created by Michał Warchalski on 24/03/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long Largest[2][100000];

void LargestValue(vector<int> B, int LastIndex)
{
    Largest[0][LastIndex] = 0;
    Largest[1][LastIndex] = 0;
    
    if (0 < LastIndex)
    {
        Largest[0][LastIndex - 1] = abs(1 - B[LastIndex]);
        Largest[1][LastIndex - 1] = max(abs(B[LastIndex - 1] - 1), abs(B[LastIndex - 1] - B[LastIndex]));
        
        for (int index = LastIndex - 2; index > -1; index--)
        {
            Largest[0][index] = max(abs(1- B[index + 1]) + Largest[1][index + 1], Largest[0][index + 1]);
            Largest[1][index] = max(abs(B[index]- B[index + 1]) + Largest[1][index + 1], abs(B[index]- 1) + Largest[0][index + 1]);
        }

    }
    
}

//long long LargestValue(vector<int> B, int FirstTerm, int FirstIndex, int LastIndex)
//{
//    long long temp = 0;
//    
//    if(FirstIndex == LastIndex)
//    {
//        return 0;
//    }
//    
//    if (Largest[FirstTerm][FirstIndex] == -1)
//    {
//        
//        if (FirstIndex == LastIndex - 1)
//        {
//            if (FirstTerm == 1)
//            {
//                Largest[FirstTerm][FirstIndex] = max(abs(B[FirstIndex] - 1), abs(B[FirstIndex] - B[LastIndex]));
//            }
//            
//            if (FirstTerm == 0)
//            {
//                Largest[FirstTerm][FirstIndex] = abs(1 - B[LastIndex]);
//            }
//            
//            //cout<< "Largest["<<FirstTerm<<"]["<<FirstIndex<<"]: "<<Largest[FirstTerm][FirstIndex]<<endl;
//            
//            return Largest[FirstTerm][FirstIndex];
//        }
//
//        
//        if (FirstTerm==1)
//        {
//                temp = max(abs(B[FirstIndex]- B[FirstIndex + 1]) + LargestValue(B, 1, FirstIndex + 1, LastIndex),  abs(B[FirstIndex]- 1) + LargestValue(B, 0, FirstIndex + 1, LastIndex));
//        }
//        if (FirstTerm==0)
//        {
//                temp = max(abs(1- B[FirstIndex + 1]) + LargestValue(B, 1, FirstIndex + 1, LastIndex), LargestValue(B, 0, FirstIndex + 1, LastIndex));
//        }
//
//        Largest[FirstTerm][FirstIndex] = temp;
//        
//        //cout<< "Largest["<<FirstTerm<<"]["<<FirstIndex<<"]: "<<Largest[FirstTerm][FirstIndex]<<endl;
//    }
//    
//    
//    
//    return Largest[FirstTerm][FirstIndex];
//    
//}
//
//long long LargestValue1(vector<int> B, int FirstIndex, int LastIndex)
//{
//    
//    if(FirstIndex == LastIndex)
//    {
//        return 0;
//    }
//    
//    return max(LargestValue(B, 1, FirstIndex, LastIndex), LargestValue(B, 0, FirstIndex, LastIndex));
//
//    
//}


int main() {
    
    int T;
    
    cin >> T;
    
    vector<long long> ans(T);
    
    
    
    for (int i = 0; i < T; i++)
    {
        int N;
        
        cin >> N;
        
        vector<int> B(N);
        
        for (int j = 0; j < N; j++)
        {
            cin >> B[j];
        }
        
//        for (int k = 0; k < 2; k++)
//        {
//            for (int l = 0; l < N; l++)
//            {
//                Largest[k][l]=-1;
//            }
//        }
        
        LargestValue(B, N - 1);
        
        ans[i] = max(Largest[0][0], Largest[1][0]);
        
        
    }
    
    for (int j = 0; j < T; j++)
    {
        cout << ans[j] << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
