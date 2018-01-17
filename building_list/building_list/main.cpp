//
//  main.cpp
//  building_list
//
//  Created by Michał Warchalski on 25/05/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;
string s;
int T;
int N;
char c;
vector<int> Letters(26, 0);
vector<int> Comb(26, 0);

void Prepare()
{
    for (int i = 0; i < 26; i++)
    {
        Comb[i] = 0;
        Letters[i] = 0;
    }
}

void Print(vector<int> Combi, int Index) // We don't go back from Index, consider only letters[i] with i >= Index
{
    
    for (int i = 0; i < 26; i++)
    {
        if (Combi[i] > Letters[i])
        {
            //Done[i] = true;
            return;
        }
    }
    
    int Printed = 0;
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < Combi[i]; j++)
        {
            char ch = 'a' + i;
            cout << ch;
            Printed++;
        }
    }
    if (Printed > 0) cout << endl;
    
    vector<int> Aux = Combi;
    
    for (int i = Index; i < 26; i++)
    {
        if (Combi[i] < Letters[i])
        {
            Combi[i]++;
            Print(Combi, i);
            Combi[i]--;
        }
    }
    
}

int main(int argc, const char * argv[])
{
    
    cin >> T;
    
    for (int t = 0; t < T; t++)
    {
        Prepare();
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> c;
            Letters[c - 'a']++;
        }
        Print(Comb, 0);
    }
    
    return 0;
}
