//
//  DuduServiceMaker.cpp
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

int main() {
    
    int T;
    cin >> T;
    
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> graph[N + 1];
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
//            graph[v].push_back(u);
        }
        
        bool finded = false;
        for (int i = 1; i <= N; i++) {
            vector<bool> visited(N+1, false);
            int s = i;
            stack<int> stack;
            stack.push(s);
            
            while (!stack.empty()) {
                int u = stack.top();
                stack.pop();
                
                for (int i = 0; i < graph[u].size(); i++) {
                    int v = graph[u][i];
                    if (!visited[v]) {
                        visited[v] = true;
                        stack.push(v);
                    }
                    if (v == s) {
                        finded = true;
                        break;
                    }
                }
            }
            
            if (finded) {
                break;
            }
        }
        
        if (finded) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        
        if (T >= 0) {
            cout << endl;
        }
    }
    
    return 0;
}
