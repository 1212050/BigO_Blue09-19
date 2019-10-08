//
//  RoyAndTrendingTopic.cpp
//  Heap_L07
//
//  Created by manhduydl on 10/4/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

struct Topic {
    int id;
    ll cScore;
    Topic(int id, ll cScore) {
        this->id = id;
        this->cScore = cScore;
    }
};

int main() {
    
    int N;
    cin >> N;
//    priority_queue<Topic, vector<Topic>, >
    
    for (int i = 0; i < N; i++) {
        ll oScore, p, l, c, s;
        cin >> oScore >> p >> l >> c >> s;
        ll nScore = p*50 + l*5 + c*10 + s*20;
        ll cScore = nScore = oScore;
        
    }
    
    return 0;
}
