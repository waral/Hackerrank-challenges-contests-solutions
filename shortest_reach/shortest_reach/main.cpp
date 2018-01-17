//
//  main.cpp
//  shortest_reach
//
//  Created by Michał Warchalski on 19/03/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

class Graph
{

public:
    
    vector< vector< bool > > Adjacent;
    
    Graph(int n);
    
    void add_edge(int u, int v);
    
    vector<int> shortest_reach(int start);
    
    
};

Graph::Graph(int n)
{
    Adjacent.resize(n);
    
    for (int i=0; i < n ; i++)
    {
        Adjacent[i].resize(n);
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Adjacent[i][j] = false;
        }
    }
    
}

void Graph::add_edge(int u, int v)
{
    Adjacent[u][v] = true;
    Adjacent[v][u] = true;
}

vector<int> Graph::shortest_reach(int start)
{
    unsigned long size = Adjacent[0].size();

    vector<int> temp;
    
    temp.resize(size);
    
    int CurrentIndex;
    
    for (int i = 0; i < size ; i++)
    {
        temp[i]=-1;
    }
    
    temp[start] = 0;
    
    
    //vector<bool> visited(size);
    
    list <int> to_visit;
    
    for (int i; i < size; i++)
    {
        if (Adjacent[start][i])
        {
            to_visit.push_back(i);
            temp[i] = 6;
        }
    }
    
    int distance=0;
    
    while (!to_visit.empty())
    {
        distance++;
        
        CurrentIndex=to_visit.front();
        
        for ( int i = 0; i < size; i++ )
        {
            if( Adjacent[CurrentIndex][i] and temp[i] == -1 )
            {
                to_visit.push_back(i);
                temp[i] = temp[CurrentIndex] + 6;
            }
        }
        
        to_visit.pop_front();
        
    }
    
    return temp;
}


int main()
{
    
    int queries;
    
    cin >> queries;
    
    vector< vector<int> > distances;
    
    distances.resize(queries);
    
    vector<int> startId(queries);
    
    for (int t = 0; t < queries; t++)
    {
        
        int n, m;
        
        cin >> n;
        // Create a graph of size n where each edge weight is 6:
        
        Graph graph(n);
        
        cin >> m;
        // read and set edges
        
        for (int i = 0; i < m; i++)
        {
            int u, v;
            
            cin >> u >> v;
            
            u--, v--;
            // add each edge to the graph
            
            graph.add_edge(u, v);
        }
        
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
