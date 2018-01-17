//
//  main.cpp
//  cutting_boards
//
//  Created by Michał Warchalski on 02/04/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

long long Big = 1000000007;

long long MinCost(multiset<long long> &Cx, multiset<long long> &Cy)
{
    long long Cost = 0;
    long long VerticalPieces = 1;
    long long HorizontalPieces = 1;
    
    while (!Cx.empty() and !Cy.empty())
    {
        if (*Cx.rbegin() > *Cy.rbegin())
        {
            long long temp = *Cx.rbegin();
            
            Cx.erase(Cx.find(temp));
            
            Cost = (Cost + HorizontalPieces * temp) % Big;
            
            VerticalPieces++;
            
            continue;
        }
        
        if (*Cx.rbegin() <= *Cy.rbegin())
        {
            long long temp = *Cy.rbegin();
            
            Cy.erase(Cy.find(temp));
            
            Cost = (Cost + VerticalPieces * temp) % Big;
            
            HorizontalPieces++;
            continue;
        }
    }
    
    while (!Cx.empty())
    {
        long long temp = *Cx.rbegin();
        
        Cx.erase(Cx.find(temp));
        
        Cost = (Cost + HorizontalPieces * temp) % Big;
        
        //VerticalPieces++;
    }

    while (!Cy.empty())
    {
        long long temp = *Cy.rbegin();
        
        Cy.erase(Cy.find(temp));
        
        Cost = (Cost + VerticalPieces * temp) % Big;
        
        //VerticalPieces++;
    }
    
    return Cost;

}


int main() {
    
    int q;
    
    scanf("%d",&q);
    
    long long ans[q];
    
    for (int i = 0; i < q; i++)
    {
        long long m,n;
        
        scanf("%lld %lld", &m, &n);
        
        multiset<long long> cx, cy;
        
        for (long long j = 0; j < m - 1; j++)
        {
            long long c;
            
            scanf("%lld", &c);
            
            cy.insert(c);
        }
        
        for (long long j = 0; j < n - 1; j++)
        {
            long long c;
            
            scanf("%lld", &c);
            
            cx.insert(c);
        }
        
        ans[i] = MinCost(cx, cy);
        
    }
    
    for (int i = 0 ; i < q; i++)
    {
        printf("%lld\n", ans[i]);
    }
    
    return 0;
}
