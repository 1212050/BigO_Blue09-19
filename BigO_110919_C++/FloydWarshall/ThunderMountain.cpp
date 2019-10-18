//
//  ThunderMountain.cpp
//  FloydWarshall
//
//  Created by manhduydl on 10/18/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

#define INF 1e9

vector<vector<double>> graph;
vector<vector<double>> dist;
int V;

struct Point {
    int x;
    int y;
    
    double distance(Point other) {
        return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
    }
};

bool floydWarshall(vector<vector<double>> &dist) {
    
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
    int testCase = 1;
    
    while (T--) {
        cin >> V;
        
        graph = vector<vector<double>>(V, vector<double>(V, INF));
        
        vector<Point> vertexs;
        for (int i = 0; i < V; i++) {
            int x, y;
            cin >> x >> y;
            vertexs.push_back({x, y});
        }
        
        for (int i = 0; i < V; i++) {
            for (int j = i; j < V; j++) {
                double w = vertexs[i].distance(vertexs[j]);
                if (w <= 10) {
                    graph[i][j] = w;
                    graph[j][i] = w;
                }
            }
        }
        
        dist = graph;
        
        floydWarshall(dist);
        
        double result = -1;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] > result) {
                    result = dist[i][j];
                }
            }
        }
        
        double rounded = round(result * 10000.0) / 10000.0;
        cout << "Case #" << testCase << ":" << endl;
        if (result == INF) {
            cout << "Send Kurdy";
        } else {
            cout << fixed << setprecision(4) << rounded;
        }
        
        if (T > 0) {
            cout << endl << endl;
        }
        
        testCase++;
    }
    
    return 0;
}
