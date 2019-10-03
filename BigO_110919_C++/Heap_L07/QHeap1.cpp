//
//  QHeap1.cpp
//  Heap_L07
//
//  Created by manhduydl on 10/3/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<long long> h;

void minHeapify(int i) {
    
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    int min = i;
    if (left < h.size() && h[left] < h[min]) {
        min = left;
    }
    if (right < h.size() && h[right] < h[min]) {
        min = right;
    }
    
    if (min != i) {
        swap(h[min], h[i]);
        minHeapify(min);
    }
}

void pushMinHeap(long long v) {
    h.push_back(v);
    int i = (int)h.size() - 1;
    int nodeP = (i - 1)/2;
    
    while (i != 0 && h[nodeP] > h[i]) {
        swap(h[nodeP], h[i]);
        i = nodeP;
        nodeP = (i - 1)/2;
    }
}

void deleteMinHeap(long long v) {
    for (int i = 0; i < h.size(); i++) {
        if (h[i] == v) {
            h[i] = h[h.size() - 1];
            h.pop_back();
            for (int j = (int)(h.size()/2 - 1); j >= 0; j--) {
                minHeapify(i);
            }
            break;
        }
    }
}

int main() {
    
    int Q;
    cin >> Q;
    
    while (Q--) {
        int command;
        cin >> command;
        
        long long v;
        if (command == 1) {
            cin >> v;
            pushMinHeap(v);
        }
        else if (command == 2) {
            cin >> v;
            deleteMinHeap(v);
        }
        else if (command == 3) {
            if (!h.empty()) {
                cout << h[0] << endl;
            }
        }
    }
    
    return 0;
}
