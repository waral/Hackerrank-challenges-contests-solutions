//
//  main.cpp
//  prim_mst
//
//  Created by Michał Warchalski on 02/04/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <set>
#include <queue>

using namespace std;

class Graph
{
    
public:
    
    vector< vector <pair <int, int>>  > G;
    
    vector < vector <pair <bool , int> >> Adjacent;
    
    vector < bool > Marked;
    
    Graph(long long n);
    
    void add_edge(int u, int v, int w);
    
    long long Prim();
    
    
};

Graph::Graph(long long n)
{
    G.resize(n);
    
    Adjacent.resize(n);
    
    for (int u = 0; u < n ; u++)
    {
        Adjacent[u].resize(n);
        for (int v = 0; v < n;  v++)
        {
            Adjacent[u][v].first = false;
            Adjacent[u][v].second = 0;
        }
    }
    
    Marked.resize(n);
}

void Graph::add_edge(int u, int v, int w)
{
    //    G[u].push_back({ v, w });
    //
    //    G[v].push_back({ u, w });
    
    Adjacent[u][v].first = true;
    Adjacent[v][u].first = true;
    
    Adjacent[u][v].second = w;
    Adjacent[v][u].second = w;
    
}

long long Graph::Prim()
{
    unsigned long size = G.size();
    
    long long MinCost = 0;
    
    set < pair <long long, int> > Q;
    
    Q.insert({ 0, 0});
    
    while (!Q.empty())
    {
        auto top = Q.begin();
        
        int u = top->second;
        
        Q.erase(top);
        
        if (Marked[u] == true)
        {
            continue;
        }
        
        MinCost += top->first;
        
        Marked[u] = true;
        
        for (int v = 0; v < size; v++)
        {
            if(Adjacent[u][v].first == true and Marked[v] == false)
            {
                Q.insert({Adjacent[u][v].second, v});
            }
        }
        
    }
    
    return MinCost;
}


int main()
{
    int N;
    long long M;
    
    scanf("%d %lld", &N, &M);
    
    Graph graph(N);
    
    vector<long long> distances;
    
    distances.resize(M);
    
    
        for (int i = 0; i < M; i++)
        {
            int u, v, w;
            
            // cin >> u >> v >> w;
            
            scanf("%d %d %d", &u, &v, &w);
            
            u--, v--;
            
            if (graph.Adjacent[u][v].first == true and graph.Adjacent[u][v].second <= w)
            {
                continue;
            }
            
            if (graph.Adjacent[u][v].first == true and graph.Adjacent[u][v].second > w)
            {
                graph.Adjacent[u][v].second = w;
                graph.Adjacent[v][u].second = w;
                continue;
            }
            
            
            // add each edge to the graph
            
            graph.add_edge(u, v, w);
        }
        
    printf("%lld", graph.Prim());
    
    return 0;
}


