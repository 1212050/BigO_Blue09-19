//
//  ALLIZZWELL.cpp
//  DFS_L06
//
//  Created by manhduydl on 10/1/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

const string result = "ALLIZZWELL";
#define MAX 101
char graph[MAX][MAX];
bool visited[MAX][MAX];
bool found = false;

class Point {
public:
    int x, y;
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    
    Point operator+ (Point other) {
        return Point(x + other.x, y + other.y);
    }
    
    bool operator== (Point other) {
        return this->x == other.x && this->y == other.y;
    }
};

Point Next[8] = {
    Point(-1, -1),
    Point(-1, 0),
    Point(-1, 1),
    Point(0, 1),
    Point(1, 1),
    Point(1, 0),
    Point(1, -1),
    Point(0, -1)
};

bool isvalid(Point p, int R, int C) {
    return p.x >= 0 && p.x < R && p.y >= 0 && p.y < C;
}

void DFS(Point s, int R, int C, int index) {
    if (index == 10) {
        found = true;
        return;
    }
    
//    visited[s.x][s.y] = true;
    char c = result[index];
    
    for (Point p : Next) {
        Point u = s + p;
        char currentC = graph[u.x][u.y];
        if (isvalid(u, R, C) && currentC == c && !visited[u.x][u.y]) {
            visited[u.x][u.y] = true;
            DFS(u, R, C, index+1);
            visited[u.x][u.y] = false;
        }
    }
}

int main() {
    
    int T;
    cin >> T;
    
    while (T--) {
        
        int R, C;
        cin >> R >> C;
        
        for (int i = 0; i < R; i++) {
            cin >> graph[i];
        }
        
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                visited[i][j] = false;
            }
        }
        
        found = false;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (graph[i][j] == 'A') {
                    Point s = Point(i, j);
                    visited[s.x][s.y] = true;
                    DFS(s, R, C, 1);
                    visited[s.x][s.y] = false;
                    if (found) {
                        break;
                    }
                }
            }
            if (found) {
                break;
            }
        }
        
        if (found) {
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
