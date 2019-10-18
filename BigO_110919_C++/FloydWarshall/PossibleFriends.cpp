//
//  PossibleFriends.cpp
//  FloydWarshall
//
//  Created by manhduydl on 10/16/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAX 51
#define INF 1e9

vector<vector<int>> graph;
vector<vector<int>> dist;
int V;

bool floydWarshall(vector<vector<int>> &graph, vector<vector<int>> &dist) {
    
    dist = graph;
    
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    
    int T;
    cin >> T;
    
    while (T--) {
        string s;
        cin >> s;
        V = (int)s.length();
        
        graph = vector<vector<int>>(V, vector<int>(V));
        dist = vector<vector<int>>(V, vector<int>(V));
        
        for (int j = 0; j < V; j++) {
            if (j == 0) {
                graph[0][j] = 0;
            }
            else {
                if (s[j] == 'N') {
                    graph[0][j] = INF;
                }
                else {
                    graph[0][j] = 1;
                }
            }
        }
        for (int i = 1; i < V; i++) {
            for (int j = 0; j < V; j++) {
                char c;
                cin >> c;
                if (j == i) {
                    graph[i][j] = 0;
                }
                else {
                    if (c == 'N') {
                        graph[i][j] = INF;
                    } else {
                        graph[i][j] = 1;
                    }
                }
            }
        }
        
        floydWarshall(graph, dist);
        
        int result = 0;
        int count = 0;
        for (int i = 0; i < V; i++) {
            int temp = 0;
            for (int j = 0; j < V; j++) {
                if (dist[i][j] == 2) {
                    temp += 1;
                }
            }
            if (temp > count) {
                result = i;
                count = temp;
            }
        }
        
        cout << result << " " << count << endl;
    }
    
    return 0;
}
