//
//  main.cpp
//  dijkstra_shortest_reach_onsets
//
//  Created by Michał Warchalski on 26/03/17.
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
    
    Graph(long long n);
    
    void MakeGraph();
    
    void add_edge(int u, int v, int w);
    
    vector<long long> shortest_reach(int start);
    
    
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

void Graph::MakeGraph()
{
    for (int u = 0; u < G.size(); u++)
    {
        for (int v = 0; v < G.size(); v++)
        {
            if (Adjacent[u][v].first == true)
            {
                int w = Adjacent[u][v].second;
                G[u].push_back({ v, w });
            }
        }
    }
}

vector<long long> Graph::shortest_reach(int start)
{
    unsigned long size = G.size();
    
    vector<long long> D( size, -1 );
    
    D[start] = 0;
    
    set < pair <long long, int> > Q;
    
    Q.insert({ D[start], start});
    
    while (!Q.empty())
    {
        auto top = Q.begin();
        
        int u = top->second;
        
        Q.erase(top);
        
        for (auto next : G[u])
        {
            int v = next.first;
            int weight = next.second;
            
            if (D[u] + weight < D[v])
            {
                Q.erase(Q.find({ D[v], v}));
                D[v] = D[u] + weight;
                Q.insert({D[v], v});
            }
            if (D[v] == -1)
            {
                D[v] = D[u] + weight;
                Q.insert({D[v], v});
            }
        }
        
    }
    
    return D;
}


int main()
{
    
    int queries;
    
    cin >> queries;
    
    vector< vector<long long> > distances;
    
    distances.resize(queries);
    
    vector<int> startId(queries);
    
    for (int t = 0; t < queries; t++)
    {
        
        long long n;
        
        long long m;
        
        cin >> n;
        
        Graph graph(n);
        
        cin >> m;
        
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            
            cin >> u >> v >> w;
            
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
        
        graph.MakeGraph();
        
        cin >> startId[t];
        
        startId[t]--;
        // Find shortest reach from node s
        distances[t].resize(n);
        
        distances[t]= graph.shortest_reach(startId[t]);
        
        
    }
    
    for (int t = 0; t < queries; t++)
    {
        for (int i = 0; i < distances[t].size(); i++)
        {
            if (i != startId[t])
            {
                cout << distances[t][i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
