//
//  main.cpp
//  journey_to_the_moon
//
//  Created by Michał Warchalski on 18/04/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>

using namespace std; // }}}
vector<int> countries(100000, 0);
vector<bool> visited(100000, false);

int Countries(vector<list<int>> Pairs)
{
    list<int> ToVisit;
    int size = Pairs.size();
    int CountryNo=-1;
    
    for (int u = 0; u < size; u++)
    {
        if (visited[u] == true)
        {
            continue;
        }
        
        CountryNo++;
        ToVisit.push_back(u);
        
        while (!ToVisit.empty())
        {
            int v = ToVisit.front();
            ToVisit.pop_front();
            
            if (visited[v] == true)
            {
                continue;
            }
            
            visited[v] = true;
            countries[CountryNo]++;
            
            while (!Pairs[v].empty())
            {
                int w = Pairs[v].front();
                
                if (visited[w] == false)
                {
                    ToVisit.push_back(w);
                }
                
                
                Pairs[v].pop_front();
                    
            }
        }
        
            
    }
    
    return CountryNo;
}


long long Ways(int CountriesNumber)
{
    long long Ways = 0;
    long long Total=0;
    
    for (int i = 0; i < CountriesNumber; i++)
    {
        Total += countries[i];
    }
    
    Total = 0;
    
    for (int i = 0; i < CountriesNumber; i++)
    {
        Ways += countries[i]*Total;
        Total += countries[i];
        
    }
    
    return Ways;
}


int main()
{
    int N, I;
    cin >> N >> I;
    vector<list<int> > pairs(N);
    
    for (int i = 0; i < I; ++i)
    {
        int a, b;
        cin >> a >> b;

            pairs[a].push_back(b);
            pairs[b].push_back(a);

    }
    
    int NumberOfCountries = Countries(pairs) + 1;
    
    long long result = Ways(NumberOfCountries);
 
    cout << result << endl;
    return 0;
}
