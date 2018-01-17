//
//  main.cpp
//  dreamplay_string_game
//
//  Created by Michał Warchalski on 14/06/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int q;
string s, p;

string WhoWins()
{
    int SizeStr = (int)s.size();
    int SizePat = (int)p.size();
    
    if (SizeStr < SizePat)
    {
        return "Steven";
    }
    
    if ((SizeStr - SizePat) % 2 == 0)
    {
        int start = (SizeStr - SizePat)/2;
        if (s.compare(start, SizePat, p) == 0)  return "Amanda";
        
        if (SizeStr > SizePat)
        {
            int start1 = (SizeStr - SizePat)/2 - 1;
            int start2 = (SizeStr - SizePat)/2 + 1;
            if (s.compare(start1, SizePat, p) == 0 and s.compare(start2, SizePat, p) == 0)  return "Amanda";
        }
    }
    
    int start1 = (SizeStr - SizePat)/2;
    int start2 = (SizeStr - SizePat)/2 + 1;
    if (s.compare(start1, SizePat, p) == 0 and s.compare(start2, SizePat, p) == 0)  return "Amanda";
    
    
    return "Steven";
}

int main()
{
    cin >> q;
    
    while (q--)
    {
        cin >> s;
        cin >> p;
        cout << WhoWins() << endl;
    }
    
    return 0;
}









