//
//  chores_L03P01.cpp
//  BigO_110919_C++
//
//  Created by manhduydl on 9/20/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    int n, P, V;
    cin >> n >> P >> V;
    
    vector<int> chores(n);
    for (int i = 0; i < n; i++) {
        cin >> chores[i];
    }
    
    sort(chores.begin(), chores.end());
    
    if (chores[V] - chores[V-1] > 0) {
        cout << chores[V] - chores[V-1];
        return 0;
    }
    
    cout << 0;
    
    return 0;
}
