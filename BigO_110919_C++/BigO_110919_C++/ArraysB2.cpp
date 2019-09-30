//
//  ArraysB2.cpp
//  BigO_110919_C++
//
//  Created by manhduydl on 9/14/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int n, k;
    cin >> n >> k;
    
    if (k == 0) {
        cout << -1 << " " << -1;
        return 0;
    }
    if (k == 1) {
        cout << 1 << " " << 1;
        return 0;
    }
    
    vector<int> V(n);
    for (int i = 0; i < n; i++) {
        cin >> V[i];
    }
    
    int count = 0, L = 0, R = 0;
    vector<int> temp(1e5, 0);
    
    while (R < n) {
        temp[V[R]] += 1;
        if (temp[V[R]] == 1) {
            count += 1;
        }
        
        if (count == k) {
            while (L <= R) {
                temp[V[L]] -= 1;
                if (temp[V[L]] == 0) {
                    cout << L+1 << " " << R+1;
                    return 0;
                }
                L += 1;
            }
            break;
        }
        R += 1;
    }
    
    cout << -1 << " " << -1;
    return 0;
}
