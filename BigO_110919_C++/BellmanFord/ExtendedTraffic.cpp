//
//  ExtendedTraffic.cpp
//  BellmanFord
//
//  Created by manhduydl on 10/16/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#define MAX 205
const int INF = 1e9;

struct Edge {
    int source;
    int target;
    int weight;
};

vector<int> dist(MAX, INF);
vector<Edge> graph;
vector<int> business(MAX);
int V, E;

bool findMinimumAmountFromZeroPoint() {
    
    int s = 1;
    dist[s] = 0;
    
    for (int i = 0; i < (V - 1); i++) {
        for (int j = 0; j < E; j++) {
            int u, v, w;
            u = graph[j].source;
            v = graph[j].target;
            w = graph[j].weight;
            
            if (dist[u] != INF && (dist[u] + w) < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    
    for (int j = 0; j < E; j++) {
        int u, v, w;
        u = graph[j].source;
        v = graph[j].target;
        w = graph[j].weight;
        
        if (dist[u] != INF && (dist[u] + w) < dist[v]) {
            return false;
        }
    }
    
    return true;
}

int main() {
    
    int T;
    cin >> T;
    int testCase = 1;
    
    while (T--) {
        cin >> V;
        
        for (int i = 1; i <= V; i++) {
            cin >> business[i];
            dist[i] = INF;
        }
        
        cin >> E;
        graph.clear();
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            graph.push_back({u, v, (int)pow((business[v] - business[u]), 3)});
        }
        
        findMinimumAmountFromZeroPoint();
        
        cout << "Case " << testCase << ":" << endl;
        
        int q;
        cin >> q;
        for (int i = 0; i < q; i++) {
            int dest;
            cin >> dest;
            if (dist[dest] >= 3 && dist[dest] != INF) {
                cout << dist[dest] << endl;
            } else {
                cout << "?" << endl;
            }
        }
        testCase++;
    }
    
    return 0;
}
