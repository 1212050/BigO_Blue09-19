//
//  main.cpp
//  DFS_L06
//
//  Created by manhduydl on 9/28/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    // init graph
    vector<int> graph[N + 1];
    for (int i = 0; i < (N - 1); i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    int Q;
    cin >> Q;
    vector<int> ids(Q);
    for (int i = 0; i < Q; i++) {
        cin >> ids[i];
    }
    
    //DFS
    vector<bool> visited(N+1, false);
    vector<int> dist(N+1, -1);
    stack<int> stack;
    int s = 1;
    stack.push(s);
    visited[s] = true;
    dist[s] = 0;
    
    while (!stack.empty()) {
        int u = stack.top();
        stack.pop();
        
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if (!visited[v]) {
                visited[v] = true;
                stack.push(v);
                dist[v] = dist[u] + 1;
            }
        }
    }
    
    int minDist = INT32_MAX;
    int result = INT32_MAX;
    for (int i = 0; i < ids.size(); i++) {
        int id = ids[i];
        if (dist[id] > 0 && dist[id] <= minDist) {
            if (dist[id] == minDist) {
                result = min(result, id);
            } else {
                result = id;
            }
            minDist = dist[id];
        }
    }
    
    cout << result;
    
    return 0;
}
