//
//  main.cpp
//  kruskal_mst
//
//  Created by Michał Warchalski on 03/04/17.
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
    
    set < pair< long long, pair<int,int> >> Edges; // (w_uv, (u,v))
    
    vector < vector <pair <bool , int> >> Adjacent;
    
    vector < int > Parent;
    
    int Root(int u);
    
    void Union(int u, int v);
    
    Graph(long long n);
    
    void add_edge(int u, int v, int w);
    
    long long Kruskal();
    
    
};

Graph::Graph(long long n)
{
    
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
    
    Parent.resize(n);
    
    for (int u = 0; u < n; u++)
    {
        Parent[u] = u;
    }
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
    
    Edges.insert({w, {u,v}});  //one is enough
   // Edges.insert({w, {v,u}});
    
}

int Graph::Root(int u)
{
    int v = u;
    
    while (Parent[v] != v)
    {
        v = Parent[v];
    }
    
    return v;
}

void Graph::Union(int u, int v)
{
    int a = Root(u);
    int b = Root(v);
    
    Parent[b] = Parent[a];
}

long long Graph::Kruskal()
{
    long long MinCost = 0;
    int NumberEdgesTree = 0;
    int NumberVertices = Adjacent.size();
    
    
    while (NumberEdgesTree < NumberVertices - 1)
    {
        auto TopEdge = Edges.begin();
        int u = TopEdge->second.first;
        int v = TopEdge->second.second;
        long long w = TopEdge->first;
        
        //cout<<"Chosen edge :"<<u+1<<" "<<v+1<<" with weight "<<w<<endl;
        
        Edges.erase(TopEdge);
        
        if (Root(u) != Root(v))
        {
            MinCost += w;
            NumberEdgesTree++;
            Union(u,v);
            
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
            graph.Edges.insert({ w, {u,v} });
            continue;
        }
        
        
        // add each edge to the graph
        
        graph.add_edge(u, v, w);
    }
    
    printf("%lld\n", graph.Kruskal());
    
    return 0;
}


