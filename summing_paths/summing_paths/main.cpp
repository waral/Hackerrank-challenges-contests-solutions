//
//  main.cpp
//  summing_paths
//
//  Created by Michał Warchalski on 23/05/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <list>
#include <string>
#include <math.h>

using namespace std;

int const MAXSIZE = 123456;
vector<vector<pair<int, long long>>> Tree(MAXSIZE); // number, weight
vector<int> Parent(MAXSIZE);
vector<int> Color(MAXSIZE);
int N;
long long CountRed = 0;
long long CountBlack = 0;
long long TotalBlack = 0;
long long TotalRed = 0;
long long Answer = 0;
int current;

void DFS(int Root, long long Weight)
{
    long long OldCountRed = CountRed;
    long long OldCountBlack = CountBlack;
    
    if (Color[Root] == 0)
    {
        CountBlack++;
    }
    else  CountRed++;
    
    while (!Tree[Root].empty())
    {
        int Vert = Tree[Root].back().first;
        long long W    = Tree[Root].back().second;
        
        if (Parent[Root] != Vert)
        {
            Parent[Vert] = Root;
            DFS(Vert, W);
        }
        
        Tree[Root].pop_back();
    }
    
    long long SubTreeCardRed = CountRed - OldCountRed;
    long long SubTreeCardBlack = CountBlack - OldCountBlack;
    
    if (Weight > -1)
    {
        Answer += SubTreeCardBlack*(TotalRed - SubTreeCardRed)*Weight;
        Answer += SubTreeCardRed*(TotalBlack - SubTreeCardBlack)*Weight;
    }
    
}


using namespace std;

int main(int argc, const char * argv[])
{
    cin >> N;
  
    for(int i = 1; i <= N; i++)
    {
        cin >> Color[i];
        if (Color[i] == 0)
        {
            TotalBlack++;
        }
        else TotalRed++;
    }
    
    for(int a0 = 0; a0 < N-1; a0++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Tree[u].push_back({v, w});
        Tree[v].push_back({u, w});
    }
    
    Parent[1] = 1;
    
    DFS(1, -1);
    
    cout << Answer << endl;
    
    return 0;
    
    
    
    
    
    
}
