//
//  TheLastShot.cpp
//  DFS_L06
//
//  Created by manhduydl on 10/1/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int DFS(int s, vector<bool> &visited, vector<int> graph[]) {
    stack<int> stack;
    stack.push(s);
    visited[s] = true;
    int count = 1;
    
    while (!stack.empty()) {
        int u = stack.top();
        stack.pop();
        
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if (!visited[v]) {
                visited[v] = true;
                stack.push(v);
                count += 1;
            }
        }
    }
    
    return count;
}

int main() {
    
    int N, M;
    cin >> N >> M;
    
    vector<int> graph[N + 1];
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    
    int maxCount = 0;
    for (int i = 1; i <= N ; i++) {
        int s = i;
        vector<bool> visited(N+1, false);
        int count = DFS(s, visited, graph);
        if (count > maxCount) {
            maxCount = count;
        }
    }
    
    cout << maxCount;
    
    return 0;
}
