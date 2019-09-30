//
//  Arrays.cpp
//  BigO_110919_C++
//
//  Created by manhduydl on 9/13/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int na, nb;
    cin >> na >> nb;
    
    int k, m;
    cin >> k >> m;
    
    vector<int> A, Ak;
    vector<int> B, Bm;
    
    int temp;
    for (int i = 0; i < na; i++) {
        cin >> temp;
        A.push_back(temp);
        if (i < k) {
            Ak.push_back(temp);
        }
    }
    
    for (int i = 0; i < nb; i++) {
        cin >> temp;
        B.push_back(temp);
        if (i >= (nb - m)) {
            Bm.push_back(temp);
        }
    }

    if (Ak.back() < Bm.front()) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    
    return 0;
}
