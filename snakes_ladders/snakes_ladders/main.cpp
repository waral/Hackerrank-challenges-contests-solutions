//
//  main.cpp
//  snakes_ladders
//
//  Created by Michał Warchalski on 14/06/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

//
//  main.cpp
//  bfs
//
//  Created by Michał Warchalski on 13/06/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <list>

using namespace std;

int const MAX = 101;
vector<bool> Visited(MAX, false);
vector<bool> SnakeLadder(MAX);
vector<int> Dist(MAX);
int N, M, T;

int Bfs(vector<list<int>> Graph)
{
    list <int> ToVisit;

    ToVisit.push_back(1);
    Dist[1] = 0;;
    
    while (!ToVisit.empty())
    {
        int top = ToVisit.front();
        ToVisit.pop_front();
        
        if (top == 100)
        {
            return Dist[top];
        }
        
        if (Visited[top])
        {
            continue;
        }
        
        //cout << "Visiting " << top << endl;
        //cout << "Distance " << Dist[top] << endl;
        Visited[top] = true;
        int dist = Dist[top] + 1;
        
        if (SnakeLadder[top])
        {
            dist = Dist[top];
        }
        
        while (!Graph[top].empty())
        {
            auto current = Graph[top].front();
            Graph[top].pop_front();
            
            if (!Visited[current])
            {
                //cout << "Pushing back " << current << " with dist " << dist << endl;
                ToVisit.push_back(current);
                
                if (Dist[current] == -1 or dist < Dist[current])
                {
                    Dist[current] = dist;
                }
            }
        }
        
    }
    
    return -1;
}

void Prepare()
{
    for (int i = 1; i <= 100; i++)
    {
        SnakeLadder[i] = false;
        Visited[i] = false;
        Dist[i] = -1;
    }
}

void PrepareBoard(vector<list<int>> &Graph)
{
    for (int i = 1; i <= 100; i++)
    {
        if (SnakeLadder[i])
        {
            continue;
        }
        for (int j = 1; j <= 6; j++)
        {
            if (i+j <= 100)
            {
                Graph[i].push_back(i+j);
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    cin >> T;
    
    while (T--)
    {
        vector<list<int>> Graph(MAX);
        Prepare();
        cin >> N;
        
        while (N--)
        {
            int start, end;
            cin >> start >> end;
            SnakeLadder[start] = true;
            Graph[start].push_back(end);
        }
        
        cin >> M;
        
        while (M--)
        {
            int start, end;
            cin >> start >> end;
            SnakeLadder[start] = true;
            Graph[start].push_back(end);
        }
        PrepareBoard(Graph);
        cout << Bfs(Graph) << endl;
    }
    
    return 0;
}












