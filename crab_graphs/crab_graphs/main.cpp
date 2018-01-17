//
//  main.cpp
//  crab_graphs
//
//  Created by Michał Warchalski on 01/06/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//


#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;

int const MAX = 210;
int N0, N, T, M, C, Source;

int rGraph[MAX][MAX];
int parent[MAX];

int Graph[MAX][MAX];
int Degree[MAX];

void Prepare()
{
    for (int i = 0; i < MAX; i++)
    {
        Degree[i] = 0;
        for (int j = 0; j < MAX; j++)
        {
            Graph[i][j] = 0;
        }
    }
}

bool bfs(int s, int t)
{
    vector<bool> visited(N, false);
    
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        
        for (int v=1; v<=N; v++)
        {
            if (visited[v]==false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    
    return (visited[t] == true);
}

int fordFulkerson(int s, int t)
{
    int u, v;
    
    for (u = 0; u <= N; u++)
        for (v = 0; v <= N; v++)
            rGraph[u][v] = Graph[u][v];
    
    int max_flow = 0;  // There is no flow initially
    
    while (bfs(s, t))
    {
        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        
        max_flow += path_flow;
    }
    
    return max_flow;
}

int main()
{
    cin >> C;
    
    while(C--)
    {
        Prepare();
        
        cin >> N0 >> T >> M;
        
        N = 2*N0 + 3;
        
        Source = N - 1;
        
        while(M--)
        {
            int u, v;
            cin >> u >> v;
            Graph[2*u][2*v + 1] = 1;
            Graph[2*v][2*u + 1] = 1;
            Graph[2*v + 1][Source] = 1;
            Graph[2*u + 1][Source] = 1;
            Degree[2*u]++;
            Degree[2*v]++;
        }
        
        for (int u = 2; u < MAX; u++)
        {
            //cout << "Degree of "<<u<<" : " << Degree[u] << endl;
            Graph[0][u] = min(Degree[u], T);
        }
        
        cout << fordFulkerson(0, Source) << endl;
    }
    
    
    
    return 0;
}











