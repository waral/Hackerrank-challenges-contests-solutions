//
//  main.cpp
//  floyd_warshall_city_of
//
//  Created by Michał Warchalski on 18/05/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int const MAXSIZE = 401;
int const INF = 1e8;
int N, M, Q;
vector<vector<int>> Graph(MAXSIZE);

void Init()
{
    for(int i = 0; i < MAXSIZE; i++)
    {
        Graph[i].resize(MAXSIZE);
        for (int j = 0; j < MAXSIZE; j++)
        {
            Graph[i][j] = INF;
        }
        Graph[i][i] = 0;
    }
}

void Floyd()
{
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                Graph[i][j] = min(Graph[i][j], Graph[i][k] + Graph[k][j]);
            }
        }
    }
    return;
}

int main(int argc, const char * argv[])
{
    cin >> N >> M;
    
    Init();
    
    for (int i = 0; i < M; i++)
    {
        int U, V, Weight;
        cin >> U >> V >> Weight;
        Graph[U][V] = Weight;
    }
    
    cin >> Q;
    Floyd();
    
    for (int q = 0; q < Q; q++)
    {
        int a, b;
        cin >> a >> b;
        if (Graph[a][b] == INF)
        {
            cout << -1<<endl;
        }
        else cout << Graph[a][b] << endl;
        
    }
    
    
    return 0;
}
