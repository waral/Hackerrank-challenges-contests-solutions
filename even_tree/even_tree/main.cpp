//
//  main.cpp
//  even_tree
//
//  Created by Michał Warchalski on 05/06/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int const MAX = 101;
int N, M;
vector< vector<int>> Graph(MAX);
vector<int> Parent(MAX, 0);
int VerticesTotal = 0;
int HowManyRemove = 0;
int current = 0;

void DFS(int Root)
{
    int VerticesOld = VerticesTotal;
    VerticesTotal++;
    
    while (!Graph[Root].empty())
    {
        current = Graph[Root].back();
        
        if( current != Parent[Root])
        {
            Parent[current] = Root;
            DFS(current);
        }
        
        Graph[Root].pop_back();
    }
    
    //cout <<"Root: "<< Root << "VerticesTotal - VerticesOld : " << VerticesTotal - VerticesOld << endl;
    if( Root != 1 and (VerticesTotal - VerticesOld) % 2 == 0)
    {
        HowManyRemove++;
    }
}

int main(int argc, const char * argv[])
{
    cin >> N >> M;
    
    while(M--)
    {
        int u, v;
        cin >> u >> v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    Parent[1] = 1;
    
    DFS(1);
    
    cout << HowManyRemove << endl;
    return 0;
}
