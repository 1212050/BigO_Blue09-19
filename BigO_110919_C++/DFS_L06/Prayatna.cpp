//
//  Prayatna.cpp
//  DFS_L06
//
//  Created by manhduydl on 9/30/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void DFS(int s, vector<bool> &visited, vector<int> graph[]) {
    stack<int> stack;
    stack.push(s);
    visited[s] = true;
    
    while (!stack.empty()) {
        int u = stack.top();
        stack.pop();
        
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if (!visited[v]) {
                visited[v] = true;
                stack.push(v);
            }
        }
    }
}

int main() {
    
    int T;
    cin >> T;
    
    while (T--) {
        int N, E;
        cin >> N >> E;
        
        if (E == 0) {
            cout << N <<endl;
            continue;
        }
        
        vector<int> graph[N+1];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        vector<bool> visited(N, false);
        int count = 0;
        for (int i = 0; i < visited.size(); i++) {
            if (visited[i] == false) {
                count +=1;
                DFS(i, visited, graph);
            }
        }
        
        cout << count;
        if (T >=0 ) {
            cout << endl;
        }
    }
    
    return 0;
}
