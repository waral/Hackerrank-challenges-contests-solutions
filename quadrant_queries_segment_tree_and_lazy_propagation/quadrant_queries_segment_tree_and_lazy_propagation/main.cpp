//
//  main.cpp
//  quadrant_queries_segment_tree_and_lazy_propagation
//
//  Created by Michał Warchalski on 22/05/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

int const MAXINT = 123456;
int const MAXLEVEL = (int)(ceil(log2(MAXINT)));
int const MAXSIZE = 2*(int)pow(2, MAXLEVEL) - 1;
vector<vector<int>> Tree(MAXSIZE, vector<int>(4));
vector<int> Lazy(MAXSIZE, 0);
vector<vector<int>> Quadrant(MAXINT, vector<int> (4, 0));
int N, Q;
vector<vector<int>> Alg(4, vector<int>(4));

void PrepareAlg()
{
    for(int i = 0; i < 4; i++)
    {
        Alg[i][i] = 0;
    }
    
    for (int i = 0 ; i < 4; i++)
    {
        Alg[0][i] = i;
        Alg[i][0] = i;
    }
    
    Alg[1][2] = 3;
    Alg[2][1] = 3;
    
    Alg[1][3] = 2;
    Alg[3][1] = 2;
    
    Alg[2][3] = 1;
    Alg[3][2] = 1;

}


vector<int> Plus(vector<int> V, vector<int> W)
{
    vector<int> Result(4, 0);
    
    for (int i = 0; i < 4; i++)
    {
        Result[i] = V[i] + W[i];
    }
    
    return Result;
}

vector<int> Op(int A, vector<int> V)
{

    if (A == 1)
    {
        swap(V[0], V[3]);
        swap(V[1], V[2]);
        
        return V;
    }
    
    if (A == 2)
    {
        swap(V[0], V[1]);
        swap(V[2], V[3]);
        
        return V;
    }
    
    if (A == 3)
    {
        swap(V[0], V[2]);
        swap(V[1], V[3]);
        
        return V;
    }

    return V;
}


int getMid(int s, int e) {  return s + (e -s)/2;  }


vector<int> getSumUtil(int ss, int se, int qs, int qe, int si)
{
    
    vector<int> Aux(4,0);
    
    if (Lazy[si] != 'I')
    {
        Tree[si] = Op(Lazy[si], Tree[si]);
       
        if (ss != se)
        {
            Lazy[si*2+1] = Alg[Lazy[si]][Lazy[si*2 + 1]];
            Lazy[si*2+2] = Alg[Lazy[si]][Lazy[si*2 + 2]];
        }
        
        Lazy[si] = 0;
    }
    
    if (ss > se || se < qs || ss > qe)
        return Aux;

    if (qs <= ss && qe >= se)
    return Tree[si];
    
    int mid = getMid(ss, se);
    
    return Plus(getSumUtil(ss, mid, qs, qe, 2*si+1), getSumUtil(mid+1, se, qs, qe, 2*si+2));
}

vector<int> getSum(int qs, int qe)
{
    if (qs < 0 || qe > N-1 || qs > qe)
    {
        vector<int> Aux(4,-1);
        printf("Invalid Input");
        return Aux;
    }
    
    return getSumUtil(0, N-1, qs, qe, 0);
}


void updateRangeUtil(int si, int ss, int se, int us, int ue, int diff)
{
    if (Lazy[si] != 0)
    {
        Tree[si] = Op(Lazy[si], Tree[si]);
        
        if (ss != se)
        {
            Lazy[si*2 + 1]   = Alg[Lazy[si]][Lazy[si*2 + 1]];
            Lazy[si*2 + 2]   = Alg[Lazy[si]][Lazy[si*2 + 2]];
        }
        
        Lazy[si] = 0;
    }
    
    // out of range
    if (ss>se || ss>ue || se<us)
        return ;
    
    // Current segment is fully in range
    if (ss>=us && se<=ue)
    {
        Tree[si] = Op(diff, Tree[si]);
        
        if (ss != se)
        {
            Lazy[si*2 + 1]   = Alg[diff][Lazy[si*2 + 1]];
            Lazy[si*2 + 2]   = Alg[diff][Lazy[si*2 + 2]];
        }
        return;
    }
    
    int mid = (ss+se)/2;
    updateRangeUtil(si*2+1, ss, mid, us, ue, diff);
    updateRangeUtil(si*2+2, mid+1, se, us, ue, diff);
    
    Tree[si] = Plus(Tree[si*2+1], Tree[si*2+2]);
}

void updateRange(int us, int ue, int diff)
{
    updateRangeUtil(0, 0, N-1, us, ue, diff);
}

void constructSTUtil(int ss, int se, int si)
{
    if (ss == se)
    {
        for (int i = 0; i < 4; i++)
        {
            Tree[si][i] = Quadrant[ss][i];
        }
        
        return;
    }
    
    int mid = getMid(ss, se);
    
    constructSTUtil(ss, mid, si*2+1);
    constructSTUtil(mid+1, se, si*2+2);
    
    Tree[si] = Plus(Tree[si*2 + 1], Tree[si*2 + 2]);
}

void constructST()
{
    constructSTUtil(0, N-1, 0);
}


int main()
{
    cin >> N;
    
    PrepareAlg();
    
    for (int i = 0; i < N; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        
        if (x > 0 and y > 0 )
        {
            Quadrant[i][0] = 1;
        }
        if (x < 0 and y > 0 )
        {
            Quadrant[i][1] = 1;
        }
        if (x < 0 and y < 0 )
        {
            Quadrant[i][2] = 1;
        }
        if (x > 0 and y < 0 )
        {
            Quadrant[i][3] = 1;
        }
        
    }
    
    constructST();
    
    cin >> Q;
    
    for (int q = 0; q < Q; q++)
    {
        char Query;
        int i, j;
        scanf(" %c %d %d", &Query, &i, &j);
        i--; j--; //careful
        
        if (Query == 'C')
        {
            vector<int> Answer = getSum(i, j);
            
            for (int k = 0; k < 4; k++)
            {
                printf("%d ", Answer[k]);
            }
            printf("\n");
        }
        
        else
        {
            updateRange(i, j, Query - 'W');
        }
    }
    
    return 0;
}

















