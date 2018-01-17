//
//  main.cpp
//  longest_common_subsequence
//
//  Created by Michał Warchalski on 19/05/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> A(101);
vector<int> B(101);
vector<vector<vector<int>>> LCS(101, vector<vector<int>>(101));

void LongestCS()
{
    
    for (int i = 1 ; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (A[i] == B[j])
            {
                LCS[i][j] = LCS[i-1][j-1];
                LCS[i][j].push_back(A[i]);
            }
            else
            {
                if (LCS[i][j-1].size() > LCS[i-1][j].size())
                {
                    LCS[i][j] = LCS[i][j-1];
                }
                else LCS[i][j] = LCS[i-1][j];
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    cin >> N >> M;
    
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }
    
    for (int i = 1; i <= M; i++)
    {
        cin >> B[i];
    }
    
    LongestCS();
    
    for (int i = 0; i <= LCS[N][M].size() - 1; i++)
    {
        cout << LCS[N][M][i] << " ";
    }
    cout << endl;
    
    return 0;
}
