//
//  main.cpp
//  BellmanFord
//
//  Created by manhduydl on 10/15/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

#define MAX 1001
const int INF = 1e9;

struct Edge {
    int source;
    int target;
    int weight;
};

vector<Edge> graph;
vector<int> dist(MAX, INF);
int n, m;

bool checkCycleExist(int s) {
    
    int u, v, w;
    dist[s] = 0;
    
    for (int i = 0; i < (n - 1); i++) {
        for (int j = 0; j < m; j++) {
            u = graph[j].source;
            v = graph[j].target;
            w = graph[j].weight;
            
            if (dist[u] != INF && (dist[u] + w) < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    
    // check
    for (int j = 0; j < m; j++) {
        u = graph[j].source;
        v = graph[j].target;
        w = graph[j].weight;
        
        if (dist[u] != INF && (dist[u] + w) < dist[v]) {
            return true;
        }
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int c;
    cin >> c;
    
    while (c--) {
        cin >> n >> m;
        
        graph.clear();
        for (int i = 0; i < m; i++) {
            int s, t, w;
            cin >> s >> t >> w;
            graph.push_back({s, t, w});
        }
        
        bool result = checkCycleExist(0);
        
        if (result) {
            cout << "possible";
        } else {
            cout << "not possible";
        }
        cout << endl;
    }
    
    return 0;
}
