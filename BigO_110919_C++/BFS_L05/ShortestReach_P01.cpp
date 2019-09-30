//
//  ShortestReach_P01.cpp
//  BFS_L05
//
//  Created by manhduydl on 9/25/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 1001
#define length 6

int main() {
    
    int Q;
    cin >> Q;
    
    while (Q--) {
        int N, M;
        cin >> N >> M;
        
        // init graph
        vector<int> graph[MAX];
        int u, v;
        for (int i = 0; i < M; i++) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int s;
        cin >> s;
        
        vector<bool> visited(MAX, false);
        vector<int> result(MAX, -1);
        
        //BFS
        queue<int> q;
        visited[s] = true;
        result[s] = 0;
        q.push(s);
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < graph[u].size(); i++) {
                int v = graph[u][i];
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                    result[v] = result[u] + length;
                }
            }
        }
        
        for (int i = 1; i <= N; i++) {
            if (i != s) {
                cout << result[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
