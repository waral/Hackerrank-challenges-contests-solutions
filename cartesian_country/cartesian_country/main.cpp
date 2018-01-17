//
//  main.cpp
//  cartesian_country
//
//  Created by Michał Warchalski on 23/05/17.
//  Copyright © 2017 Michał Warchalski. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <list>
#include <string>
#include <math.h>

using namespace std;

long getMaxBridges(long x1, long y1, long x2, long y2, long xC, long yC){
    
    long ans;
    
    long dimx = min(xC - x1, x2 - xC);
    long dimy = min(yC - y1, y2 - yC);
    
    ans = (dimx + 1)*(dimy + 1) + dimx*dimy - 1;
    
    
    return ans;
}

int main() {
    //  Return the maximum number of bridges the Rulers will commission.
    long x1;
    long y1;
    cin >> x1 >> y1;
    long x2;
    long y2;
    cin >> x2 >> y2;
    long xC;
    long yC;
    cin >> xC >> yC;
    long result = getMaxBridges(x1, y1, x2, y2, xC, yC);
    cout << result << endl;
    return 0;
}