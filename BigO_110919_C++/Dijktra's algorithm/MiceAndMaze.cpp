//
//  MiceAndMaze.cpp
//  Dijktra's algorithm
//
//  Created by manhduydl on 10/8/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 101
const int INF = 1e9;

struct option {
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
        return a.second > b.second;
    }
};

int main() {
    
    int N, E, T, M;
    cin >> N >> E >> T >> M;
    
    vector<pair<int, int>> graph[MAX];
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
    }
    
    int count = 0;
    for (int s = 1; s <= N; s++) {
        if (s == E) {
            count += 1;
            continue;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, option> q;
        vector<int> dist(MAX, INF);
        dist[s] = 0;
        q.push({s, 0});
        
        while (!q.empty()) {
            pair<int, int> u = q.top();
            q.pop();
            
            for (int i = 0; i < graph[u.first].size(); i++) {
                pair<int, int> next = graph[u.first][i];
                if ((next.second + u.second) < dist[next.first]) {
                    dist[next.first] = next.second + u.second;
                    q.push({next.first, dist[next.first]});
                }
            }
        }
        
        if (dist[E] <= T) {
            count += 1;
        }
    }
    
    cout << count << endl;
    
    return 0;
}
