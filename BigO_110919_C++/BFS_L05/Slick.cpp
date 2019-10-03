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

#define MAX 255
int graph[MAX][MAX];
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
    return p.r >= 0 & p.r <= R && p.c >= 0 && p.c <= C;
}

int BFS(Point s, int R, int C) {
    int count = 1;
    queue<Point> q;
    q.push(s);
    visited[s.r][s.c] = true;
    
    while (!q.empty()) {
        Point u = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            Point v = Point(u.r + dr[i], u.c + dc[i]);
            if (isValid(v, R, C) && graph[v.r][v.c] == 1 && !visited[v.r][v.c]) {
                visited[v.r][v.c] = true;
                q.push(v);
                count += 1;
            }
        }
    }
    
    return count;
}

int main() {
    
    while (true) {
        int R, C;
        cin >> R >> C;
        
        if (R == 0 && C == 0) {
            return 0;
        }
        
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> graph[i][j];
                visited[i][j] = false;
            }
        }
        
        vector<int> cnt(MAX*MAX, 0);
        int num = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (graph[i][j] == 1 && !visited[i][j]) {
                    Point s = Point(i, j);
                    int count = BFS(s, R, C);
                    cnt[count] += 1;
                    num += 1;
                }
            }
        }
        
        cout << num << endl;
        int temp = 0;
        for (int i = 0; i < MAX*MAX; i++) {
            if (cnt[i] > 0) {
                cout << i << " " << cnt[i] << endl;
                temp += cnt[i];
            }
            if (temp == num) {
                break;
            }
        }
        
    }
    
    return 0;
}
