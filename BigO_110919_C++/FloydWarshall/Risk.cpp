//
//  Risk.cpp
//  FloydWarshall
//
//  Created by manhduydl on 10/18/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

#define INF 1e9
int V = 21;
vector<vector<int>> graph;
vector<vector<int>> dist;

bool floydWarshall(vector<vector<int>> &dist) {
    
    for (int k = 1; k < V; k++) {
        for (int i = 1; i < V; i++) {
            for (int j = 1; j < V; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    for (int i = 1; i < V; i++) {
        if (dist[i][i] < 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    
    int testSet = 1;
    
    while (true) {
        
        graph = vector<vector<int>>(V, vector<int>(V, INF));
        
        for (int i = 1; i <= 19; i++) {
            int n;
            cin >> n;
            for (int j = 0; j < n; j++) {
                int x;
                cin >> x;
                graph[i][x] = 1;
                graph[x][i] = 1;
            }
        }
        
        for (int i = 1; i < V; i++) {
            graph[i][i] = 0;
        }
        
        dist = graph;
        
        floydWarshall(dist);
        
        int T;
        cin >> T;
        if (testSet > 1) {
            cout << endl << endl;
        }
        cout << "Test Set #" << testSet << endl;
        for (int i = 0; i < T; i++) {
            int s, d;
            cin >> s >> d;
            cout << setw(2) << s;
            cout << " to ";
            cout << setw(2) << d;
            cout << ": " << dist[s][d];
            if (i < (T-1)) {
                cout << endl;
            }
        }
        testSet++;
    }
    
    return 0;
}
