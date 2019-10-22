//
//  WhereIsMarble.cpp
//  BinarySearch
//
//  Created by manhduydl on 10/22/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    int testCase = 1;
    
    while (true) {
        int N, Q;
        cin >> N >> Q;
        
        if (N == 0 && Q == 0) {
            return 0;
        }
        
        vector<int> v(N);
        for (int i = 0; i < N; i++) {
            cin >> v[i];
        }
        
        sort(v.begin(), v.end());
        
        cout << "CASE# " << testCase << ":" << endl;
        
        int val;
        for (int i = 0; i < Q; i++) {
            cin >> val;
            vector<int>::iterator low;
            low = lower_bound(v.begin(), v.end(), val);
            int index = (int)(low - v.begin());
            if (index >= 0 && index < N && v[index] == val) {
                cout << val << " found at " << index + 1 << endl;
            } else {
                cout << val << " not found" << endl;
            }
        }
        testCase++;
    }
    
    return 0;
}
