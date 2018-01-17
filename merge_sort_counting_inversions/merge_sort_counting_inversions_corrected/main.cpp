//
//  main.cpp
//  counting_inversions
//
//  Created by Michał Warchalski on 11/03/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

//
//  counting_inversions.cpp
//
//
//  Created by Michał Warchalski on 11/03/17.
//
//

#include <iostream>
using namespace std;
long long inversions=0;

void MergeHalves(long long arr[], long long tmp[], long int LeftEnd, long int RightEnd)
{
    long int half = (LeftEnd + RightEnd)/2;
    long int i = LeftEnd;
    long int j = half;
    long int k = LeftEnd;
    
    while( i < half and j < RightEnd )
    {
        if ( arr[ i ] <= arr[ j ] )
        {
            tmp[ k ] = arr[ i ];
            i++;
            inversions=inversions + (j - half);
        }
        else
        {
            tmp[ k ] = arr[ j ];
            j++;
        }
        k++;
    }
    
    if (i < half)
    {
        inversions=inversions + ( half - i )*( RightEnd  - half );
    }
    
    
    while( i  < half)
    {
        tmp[ k ] = arr[ i ];
        //cout<<tmp[k]<<endl;
        i++;
        k++;
    }
    
    while( j < RightEnd)
    {
        tmp[ k ] = arr[ j ];
        j++;
        k++;
        
    }
    
    for (long int i = LeftEnd; i < RightEnd; ++i)
    {
        arr[ i ] = tmp[ i ];
    }
    
}

void MergeSort(long long array[], long long temp[], long int left, long int right)
{
    long int middle = ( right + left )/2;
    
    if (right <= left + 1)
    {
        //cout<<" first if "<<left<<" "<<right<<endl;
        return;
    }
    else
    {
        //cout << " No if " <<left<< " "<<right<< endl;
        
        MergeSort(array, temp, left, middle);
        
        //cout << " middle "<<middle<<endl;
        
        MergeSort(array, temp, middle, right);
        
        //cout<<" before MergeHalves with "<<left<<" "<<right<<endl;
        
        MergeHalves(array, temp, left, right);
    }
}


int main( )
{
    long int n,d;
    
    
    cin>>d;
    
    long long answer[15];
    long long a[100000];
    long long temporary[100000];
    
    for (long int i = 0; i < d; ++i)
    {
        
        cin>>n;
        
        inversions=0;
        
        for (long int j = 0; j < n; ++j)
        {
            cin>>a[j];
        }
        
        MergeSort( a, temporary, 0, n);
        
        answer[i]=inversions;
        
        
    }
    
    for (long int i = 0; i < d; ++i)
    {
        cout<<answer[i]<<endl;
    }
    
    
    return 0;
    
    
}