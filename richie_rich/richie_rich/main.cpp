//
//  main.cpp
//  richie_rich
//
//  Created by Michał Warchalski on 03/05/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<char> Biggest(string Number, int K)
{
    int n = (int)Number.size();
    int FirstIndex = 0;
    int SecondIndex = n-1;
    vector<bool> Changed(n, false);
    //int Moves = 0;
    vector<char> Answer;
    
    while (FirstIndex <= SecondIndex)
    {
        if (Number[FirstIndex] != Number[SecondIndex])
        {
            char Bigger = max(Number[FirstIndex], Number[SecondIndex]);
            Answer.push_back(Bigger);
            Changed[FirstIndex] = true;
            Changed[SecondIndex] = true;
            K--;
        }
        else
        {
            Answer.push_back(Number[FirstIndex]);
        }
        FirstIndex++;
        SecondIndex--;
    }
    
    if (K < 0)
    {
        vector<char> AnsAlter;
        AnsAlter.push_back('-');
        AnsAlter.push_back('1');
        return AnsAlter;
    }
    
    int size = (int) Answer.size();
    int index = 0;
    
    
    while (K > 0 and index < size)
    {
        
        if (n % 2 == 1 and index == size - 1 and Answer[index] != '9')
        {
            Answer[index] = '9';
            K--;
        }
        
        if (Changed[index] and Answer[index] != '9')
        {
            Answer[index] = '9';
            K--;
        }
        else
        {
            if (K >= 2 and Answer[index] != '9')
            {
                Answer[index] = '9';
                K -= 2;
            }
        }
        index++;
    }
    
    if (n % 2 == 0)
    {
        index = size - 1;
    }
    else index = size - 2;
    
    while (index >= 0)
    {
        Answer.push_back(Answer[index]);
        index--;
    }
    
    return Answer;
}

int main()
{
    int n;
    int k;
    cin >> n >> k;
    string number;
    cin >> number;
    
    vector<char> ans = Biggest(number, k);
    int size = (int)ans.size();
    
    for (int i = 0; i < size; i++)
    {
        cout<<ans[i];
    }
    cout << endl;
    
    
    
    
    
    
    return 0;
}

