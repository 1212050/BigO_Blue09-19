//
//  KefaAndPark_P05.cpp
//  BFS_L05
//
//  Created by manhduydl on 9/27/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    
    int N, M;
    cin >> N >> M;
    
    vector<int> cats(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> cats[i];
    }
    
    vector<int> graph[N + 1];
    for (int i = 0; i < (N - 1); i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    int s = 1;
    queue<int> q;
    q.push(s);
    vector<bool> visited(N + 1, false);
    visited[s] = true;
    vector<int> result(N + 1, 0);
    result[s] = cats[s];
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
                if (result[u] > M) {
                    result[v] = result[u];
                }
                else if (cats[v] == 1) {
                    result[v] = result[u] + 1;
                }
            }
        }
    }
    
    int count = 0;
    for (int i = 2; i <= N; i++) {
        if (result[i] <= M && graph[i].size() == 1) {
            count++;
        }
    }
    
    cout << count;
    
    return 0;
}
