//
//  main.cpp
//  merging_communities
//
//  Created by Michał Warchalski on 05/04/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
#include <vector>

std::vector<int> id;
std::vector<long long> size;
//std::vector<int> root;

int Root(int p)
{
    int x = p;
    
    while (id[x] != x)
    {
        x = id[x];
    }
    id[p] = x;
    //root[p] = x;
    return x;
}

void Union(int p1, int p2)
{
    int a = Root(p1);
    int b = Root(p2);
    
    if (a != b)
    {
        id[b]    = a;
        size[a] += size[b];
    }
    
}

int main(int argc, const char * argv[]) {
    int N,Q;
    
    scanf("%d %d", &N, &Q);
    
    id.resize(N);
    size.resize(N);
   // root.resize(N);
    
    for (int i = 0; i < N; i++)
    {
        id[i] = i;
        size[i] = 1;
       // root[i] = i;
    }
    
    for (int i = 0; i < Q; i++)
    {
        char OperationType, temp = 'A';
        int Person1, Person2;
        
        scanf(" %c",&OperationType);
        
        if (OperationType == 'Q')
        {
            scanf("%d", &Person1);
            Person1--;
            printf("%lld\n", size[Root(Person1)]);
        }
        
//        if (OperationType == 'Q' and temp == 'Q')
//        {
//            scanf("%d", &Person1);
//            Person1--;
//            printf("%lld\n", size[root[Person1]]);
//        }
        
        if (OperationType == 'M')
        {
            scanf("%d %d", &Person1, &Person2);
            Person1--;
            Person2--;
            Union(Person1, Person2);
        }
        temp = OperationType;
    }
    
    return 0;
}
