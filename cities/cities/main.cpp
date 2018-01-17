//
//  main.cpp
//  cities
//
//  Created by Michał Warchalski on 05/05/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <list>
#include <string>

using namespace std;

vector<bool> Visited(100000, false);


int MaxConnectedComponent ( vector< list<int> > connect, int n , int m)
{
    list <int> ToVisit;
    int Max = 0;
    int Number = 0;
    int size = n;
    
    
    
    
    for (int i = 0; i < size; i++)
    {
//        if (Visited[i])
//        {
//            continue;
//        }
        
        ToVisit.push_back(i);
        
        Number = 0;
        
        while (!ToVisit.empty())
        {
            int top = ToVisit.front();
            ToVisit.pop_front();
            //cout << "top " <<top<< endl;
            
            if (Visited[top])
            {
                continue;
            }
            
            Visited[top] = true;
            Number++;
            
            
            
            while (!connect[top].empty())
            {
                auto current = connect[top].front();
                //cout << "current "<<current<<endl;
                connect[top].pop_front();
                
                if (!Visited[current])
                {
                    ToVisit.push_back(current);
                }
                
                
            }
            
        }
        
        //cout <<"Number "<<Number << endl;
        
        if (Number > Max)
        {
            Max = Number;
        }

    }
    
    
    
    
    
    return Max;
}

int main(int argc, const char * argv[])
{
    int n;
    int m;
    cin >> n >> m;
    
    vector< list < int > > connections(n);
    
    for (int i = 0; i < m; i++)
    {
        int u,v;
        
        cin >> u >> v;
        
        u--;
        v--;
        
        if (u != v)
        {
            connections[u].push_back(v);
            connections[v].push_back(u);

        }
        
    }
    
    cout << MaxConnectedComponent(connections, n, m) << endl;
    
    return 0;
}
