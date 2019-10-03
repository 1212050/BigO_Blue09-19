//
//  main.cpp
//  Heap_L07
//
//  Created by manhduydl on 10/2/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> h;

void maxHeapify(int i) {
    int maximum = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if (left < h.size() && h[left] > h[maximum]) {
        maximum = left;
    }
    if (right < h.size() && h[right] > h[maximum]) {
        maximum = right;
    }
    
    if (maximum != i) {
        swap(h[i], h[maximum]);
        maxHeapify(maximum);
    }
}

void buildHeap(int n) {
    for (int i = (n/2 - 1); i >= 0; i++) {
        maxHeapify(i);
    }
}

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    priority_queue<int> pq;
    for (int i = 0; i < N; i++) {
        int u;
        cin >> u;
        
        pq.push(u);
        if (pq.size() < 3) {
            cout << -1;
        }

        else {
            int t1 = pq.top();
            pq.pop();
            int t2 = pq.top();
            pq.pop();
            int t3 = pq.top();
            cout << 1LL * t1 * t2 * t3;
            pq.push(t1);
            pq.push(t2);
        }
        cout << endl;
    }
    
    return 0;
}
