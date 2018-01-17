//
//  main.cpp
//  cut_the_tree
//
//  Created by Michał Warchalski on 15/05/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
#include<vector>

using namespace std;

int MAX = 123456;
vector< vector<int> > Tree(MAX);
vector<int> Data(MAX);
vector<long> Sum(MAX);
vector<int> Parent(MAX, -1);
long TotalSum = 0;
int current = 0;

void DFS(int Root)
{
    long StartSum = TotalSum;
    //cout << "Root "<<Root << endl;
    //cout << "Increasing total sum by "<<Data[Root]<<endl;
    TotalSum += Data[Root];
    //TotalSum++;
    //if(Tree[Root].empty()) cout << "Empty!" <<endl;
    
    while (!Tree[Root].empty())
    {
        current = Tree[Root].back();
        //cout << "Current "<< current <<endl;
        if (current != Parent[Root])
        {
            Parent[current] = Root;
            DFS(current);
        }
        Tree[Root].pop_back();
    }
    Sum[Root] = TotalSum - StartSum;
}


int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> Data[i];
    }
    
    for (int i = 0; i < n- 1; i++)
    {
        int u, v;
        cin >> u >> v;
        Tree[u].push_back(v);
        Tree[v].push_back(u);
    }
    
    Parent[1] = 1;
    DFS(1);
    
    long Answer = MAX;
    //cout << Sum[1] << endl;
    
    for (int i = 1; i <= n; i++)
    {
        if (abs(2*Sum[i] - Sum[1]) < Answer)
        {
            Answer = abs(2*Sum[i] - Sum[1]);
        }
    }
    
    cout << Answer << endl;
    
    
    return 0;
}
