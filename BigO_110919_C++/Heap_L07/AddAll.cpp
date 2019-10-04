//
//  AddAll.cpp
//  Heap_L07
//
//  Created by manhduydl on 10/3/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    
    int N;
    cin >> N;
    
    while (N) {
        priority_queue<ll, vector<ll>, greater<ll>> q;
        for (int i = 0; i < N; i++) {
            int v;
            cin >> v;
            q.push(v);
        }
        
        ll cost = 0;
        ll sum = 0;
        
        while (q.size() > 1) {
            sum = q.top();
            q.pop();
            sum += q.top();
            q.pop();
            
            cost += sum;
            q.push(sum);
        }
        cout << cost << endl;
        cin >> N;
    }
    
    return 0;
}
