//
//  ValidateTheMaze.cpp
//  BFS_L05
//
//  Created by manhduydl on 10/2/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 21
char graph[MAX][MAX];
bool visited[MAX][MAX];
int R, C;
int dr[4] = {-1, 0 , 1, 0};
int dc[4] = {0, 1, 0, -1};

class Point {
public:
    int r, c;
    Point(int r, int c) {
        this->r = r;
        this->c = c;
    }
};

bool validPoint(Point p) {
    return p.r >= 0 && p.r < R && p.c >=0 && p.c < C;
}

bool checkValidMaze(Point s, Point e) {
    
    queue<Point> q;
    q.push(s);
    
    while (!q.empty()) {
        Point u = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            Point v = Point(u.r + dr[i], u.c + dc[i]);
            if (validPoint(v) && graph[v.r][v.c] == '.') {
                if (v.r == e.r && v.c == e.c) {
                    return true;
                }
                if (!visited[v.r][v.c]) {
                    visited[v.r][v.c] = true;
                    q.push(v);
                }
            }
        }
    }
    
    return false;
}

int main() {
    
    int T;
    cin >> T;
    
    while (T--) {
        cin >> R >> C;
        
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> graph[i][j];
                visited[i][j] = false;
            }
        }
        
        // Find startPoint and endPoint
        vector<Point> sePoints;
        for (int i = 0; i < R; i++) {
            if (graph[i][0] == '.') {
                sePoints.push_back(Point(i, 0));
            }
            if (graph[i][C-1] == '.' && ((C-1) > 0)) {
                sePoints.push_back(Point(i, C-1));
            }
        }
        for (int j = 1; j < (C-1); j++) {
            if (graph[0][j] == '.') {
                sePoints.push_back(Point(0, j));
            }
            if (graph[R-1][j] == '.' && ((R-1) > 0)) {
                sePoints.push_back(Point(R-1, j));
            }
        }
        
        if (sePoints.size() != 2) {
            cout << "invalid";
        } else {
            if (checkValidMaze(sePoints[0], sePoints[1])) {
                cout << "valid";
            } else {
                cout << "invalid";
            }
        }
        
        if (T >= 0) {
            cout << endl;
        }
        
    }
    
    return 0;
}

/*
 #include <bits/stdc++.h>
 #define MAX 21
 using namespace std;
  
 const int dr[] = {0, 0, 1, -1};
 const int dc[] = {1, -1, 0, 0};
 int n, m;
 bool visited[MAX][MAX];
 string maze[MAX];
  
 struct Cell {
     int r, c;
 };
  
 bool isValid(int r, int c) {
     return r >= 0 && r < n && c >= 0 && c < m;
 }
  
 bool BFS(Cell s, Cell f) {
     queue<Cell> q;
     visited[s.r][s.c] = true;
     q.push(s);
  
     while (!q.empty()) {
         Cell u = q.front();
         q.pop();
   
         if (u.r == f.r && u.c == f.c) {
             return true;
         }
  
         for (int i = 0; i < 4; i++) {
             int r = u.r + dr[i];
             int c = u.c + dc[i];
  
             if (isValid(r, c) && maze[r][c] == '.' && !visited[r][c]) {
                 visited[r][c] = true;
                 q.push((Cell) {r, c});
             }
         }
     }
      
     return false;
 }
  
 int main() {
     int Q;
     cin >> Q;
  
     while (Q--) {
         cin >> n >> m;
  
         for (int i = 0; i < n; i++) {
             cin >> maze[i];
         }
  
         vector<Cell> entrance;
  
         for (int i = 0; i < n; i++) {
             for (int j = 0; j < m; j++) {
                 visited[i][j] = false;
                 if (maze[i][j] == '.' && (i == 0 || j == 0 || i == n - 1 || j == m - 1)) {
                     entrance.push_back((Cell) {i, j});
                 }
             }
         }
  
         if (entrance.size() != 2) {
             cout << "invalid" << endl;
         }
         else {
             Cell s = entrance[0];
             Cell f = entrance[1];
             cout << (BFS(s, f) ? "valid" : "invalid") << endl;
         }
     }
     return 0;
 }
 */
