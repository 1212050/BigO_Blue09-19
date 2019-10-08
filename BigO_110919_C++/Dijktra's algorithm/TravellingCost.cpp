
//
//  TravellingCost.cpp
//  Dijktra's algorithm
//
//  Created by manhduydl on 10/5/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 501
const int INF = 1e9;

struct option {
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
        return a.second > b.second;
    }
};

int main() {
    
    int N;
    cin >> N;
    
    vector<pair<int, int>> graph[MAX];
    for (int i = 0; i < N; i++) {
        int A, B, W;
        cin >> A >> B >> W;
        graph[A].push_back({B, W});
        graph[B].push_back({A, W});
    }
    
    int s, Q;
    cin >> s >> Q;
    vector<int> V;
    for (int i = 0; i < Q; i++) {
        int v;
        cin >> v;
        V.push_back(v);
    }
    
    vector<int> dist(MAX, INF);
    
    // Dijkstra
    priority_queue<pair<int, int>, vector<pair<int, int>>, option> q;
    q.push(make_pair(s, 0));
    dist[s] = 0;
    
    while (!q.empty()) {
        pair<int, int> top = q.top();
        q.pop();
        int u = top.first;
        int w = top.second;
        
        for (int i = 0; i < graph[u].size(); i++) {
            pair<int, int> next = graph[u][i];
            if ((w + next.second) < dist[next.first]) {
                dist[next.first] = w + next.second;
                q.push({next.first, dist[next.first]});
            }
        }
    }
    
    for (int v : V) {
        if (dist[v] == INF) {
            cout << "NO PATH" << endl;
        } else {
            cout << dist[v] << endl;
        }
    }
    
    return 0;
}
