//
//  GuiltyPrince_P04.cpp
//  BFS_L05
//
//  Created by manhduydl on 9/27/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

#define MAX 401

using namespace std;

int main() {
    
    int Q;
    cin >> Q;
    int testCase = 1;
    
    while (Q--) {
        int W, H;
        cin >> W >> H;
        
        char input[H][W];
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> input[i][j];
            }
        }
        
        // init graph
        int N = W * H;
        vector<int> graph[N];
        int index = 0;
        int s = -1;
        
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                char c = input[i][j];
                if (c != '#') {
                    if (c == '@') {
                        s = index;
                    }
                    if ((j+1) < W && input[i][j+1] != '#') {
                        graph[index].push_back(index+1);
                        graph[index+1].push_back(index);
                    }
                    if ((i+1) < H && input[i+1][j] != '#') {
                        graph[index].push_back(index + W);
                        graph[index + W].push_back(index);
                    }
                }
                index++;
            }
        }
        
        // BFS
        vector<bool> visited(N, false);
        vector<int> path(N, -1);
        queue<int> q;
        q.push(s);
        visited[s] = true;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < graph[u].size(); i++) {
                int v = graph[u][i];
                if (!visited[v]) {
                    path[v] = u;
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        
        int count = 0;
        for (int i = 0; i < N; i++) {
            if (path[i] > -1) {
                count++;
            }
        }
        
        cout << "Case " << testCase << ": " << count+1 << endl;
        testCase++;
    }
    
    return 0;
}
