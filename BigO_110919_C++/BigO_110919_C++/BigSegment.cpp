//
//  BigSegment.cpp
//  BigO_110919_C++
//
//  Created by manhduydl on 9/13/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int n;
    cin >> n;
    vector<int> text(n);
    
    vector<vector<int>> A;
    int Li, Ri;
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        cin >> Li >> Ri;
        temp.clear();
        temp.push_back(Li);
        temp.push_back(Ri);
        A.push_back(temp);
    }
    
    for (int i = 0; i < n; i++) {
        int count = 0;
        vector<int> Vi = A.at(i);
        for (int j = 0; j < n; j++) {
            vector<int> Vj = A.at(j);
            if (Vi.front() <= Vj.front() && Vj.back() <= Vi.back()) {
                count++;
            } else {
                break;
            }
        }
        if (count == n) {
            cout << i+1;
            return 0;
        }
    }
    
    cout << -1;
    return 0;
}
