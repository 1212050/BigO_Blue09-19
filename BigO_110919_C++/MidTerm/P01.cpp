//
//  Slick.cpp
//  BFS_L05
//
//  Created by manhduydl on 10/2/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 1005
int graph[MAX][MAX];
int dist[MAX][MAX];
bool visited[MAX][MAX];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

class Point {
public:
    int r, c;
    Point(int r, int c) {
        this->r = r;
        this->c = c;
    }
};

bool isValid(Point p, int R, int C) {
    return p.r >= 0 && p.r < R && p.c >= 0 && p.c < C;
}

int BFS(Point s, Point e, int R, int C) {
    
    queue<Point> q;
    q.push(s);
    visited[s.r][s.c] = true;
    dist[s.r][s.c] = 0;
    
    while (!q.empty()) {
        Point u = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            Point v = Point(u.r + dr[i], u.c + dc[i]);
            if (isValid(v, R, C) && graph[v.r][v.c] == 0 && !visited[v.r][v.c]) {
                visited[v.r][v.c] = true;
                q.push(v);
                dist[v.r][v.c] = dist[u.r][u.c] + 1;
                if (v.r == e.r && v.c == e.c) {
                    return dist[v.r][v.c];
                }
            }
        }
    }
    
    return -1;
}

int main() {
    int R, C;
    cin >> R >> C;
    
    while (true) {
        if (R == 0 && C == 0) {
            return 0;
        }
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                graph[i][j] = 0;
                dist[i][j] = 0;
                visited[i][j] = false;
            }
        }
        
        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int r, nB;
            cin >> r >> nB;
            for (int j = 0; j < nB; j++) {
                int c;
                cin >> c;
                graph[r][c] = 1;
            }
        }
        
        int sR, sC, eR, eC;
        cin >> sR >> sC >> eR >> eC;
        
        Point s = Point(sR, sC);
        Point e = Point(eR, eC);
        
        int result = BFS(s, e, R, C);
        
        cout << result;
        
        cin >> R >> C;
        if (R == 0 && C == 0) {
            return 0;
        } else {
            cout << endl;
        }
    }
    
    return 0;
}
