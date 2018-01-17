//
//  main.cpp
//  roads_in_hackerland
//
//  Created by Michał Warchalski on 17/05/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

long long const MAX = 123456;
vector<vector<pair<long long, long long>>> Tree(2*MAX+1); // (v, weight)
vector<long long> ID(2*MAX + 1);
vector<pair<long long , pair<long long, long long>>> Edges;
long long Count = 0;
vector<long long> Parent(2*MAX+1);
vector<long long> Bit(2*MAX + 1, 0);
vector<long long> BitAnswer(2*MAX + 1, 0);
long long N, M;

long long Root(long long x)
{
    while( ID[x] != x)
    {
        ID[x] = ID[ID[x]];
        x = ID[x];
    }
    
    return x;
}

void Union(long long x, long long y)
{
    long long p = Root(x);
    long long q = Root(y);
    
    ID[p] = ID[q];
}

void Kruskal()
{
    for (long long i = 0; i < M; i++)
    {
        long long U = Edges[i].second.first;
        long long V = Edges[i].second.second;
        long long W = Edges[i].first;
        
        if (Root(U) != Root(V))
        {
            Union(U, V);
            Tree[U].push_back({V, W});
            Tree[V].push_back({U, W});
        }
    }
}

void DFS(long long Root, long long Weight)
{
    long long OldCount = Count;
    Count++;
    
    while (!Tree[Root].empty())
    {
        long long Vert = Tree[Root].back().first;
        long long W    = Tree[Root].back().second;
        
        if (Parent[Root] != Vert)
        {
            Parent[Vert] = Root;
            DFS(Vert, W);
        }
        
        Tree[Root].pop_back();
    }
    
    long long SubTreeCard = Count - OldCount;
    
    if (Weight > -1)
    {
        Bit[Weight] = (N - SubTreeCard)*SubTreeCard;
    }
    
}

void Answer()
{
    for (long long i = 0; i <= 2*MAX; i++)// Convert
    {
        BitAnswer[i] = (Bit[i] % 2);
        Bit[i+1] += (Bit[i]/2);
    }
    
    long long First = 2*MAX;
    
    while (BitAnswer[First] == 0) //Ignore initial zeroes
    {
        First--;
    }
    
    for (long long i = First; i > -1; i--) //Prlong long answer
    {
        printf("%lld", BitAnswer[i]);
    }
    cout << endl;
}



int main(int argc, const char * argv[])
{

//        freopen("/Users/Waral/Documents/Coding/Algorithms and Data structures/roads_in_hackerland/test.txt", "r", stdin);
//        freopen("/Users/Waral/Documents/Coding/Algorithms and Data structures/roads_in_hackerland/testout.txt", "w", stdout);

    cin >> N >> M;
    
    for (long long i = 1; i <= N; i++)// initialize disjolong long set
    {
        ID[i] = i;
    }
    
    for (long long i = 0; i < M; i++)
    {
        long long U, V, Weight;
        scanf("%lld %lld %lld", &U, &V, &Weight);
        Edges.push_back({ Weight, { U, V } });
    }
    
    sort(Edges.begin(), Edges.end());
    
    Kruskal();
    Parent[1] = 1; //Root
    DFS(1, -1); //Count up
    Answer(); // Convert and prlong long the answer
    
    return 0;
}
