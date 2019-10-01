//
//  LakesInBerland.cpp
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

#define MAX 51
char graph[MAX][MAX];
bool visited[MAX][MAX];
int path[MAX][MAX];

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
    return p.r > 0 && p.r < (R-1) && p.c > 0 && p.c < (C-1);
}

int DFS(Point s, int R, int C, int index) {
    int count = 1;
    stack<Point> stack;
    stack.push(s);
    visited[s.r][s.c] = true;
    path[s.r][s.c] = index;
    
    while (!stack.empty()) {
        Point u = stack.top();
        stack.pop();
        
        for (int i = 0; i < 4; i++) {
            Point v = Point(u.r + dr[i], u.c + dc[i]);
            if (graph[v.r][v.c] == '.') {
                if (!isValid(v, R, C)) {
                    return -1;
                }
                // valid
                if (graph[v.r][v.c] == '.' && !visited[v.r][v.c]) {
                    visited[v.r][v.c] = true;
                    stack.push(v);
                    count += 1;
                    path[v.r][v.c] = index;
                }
            }
        }
    }
    
    return count;
}

bool needTranform(int index, vector<int> indexs) {
    for (int i : indexs) {
        if (i == index) {
            return true;
        }
    }
    return false;
}

int main() {
    
    int R, C, k;
    cin >> R >> C >> k;
    
    for (int i = 0; i < R; i++) {
        cin >> graph[i];
        for (int j = 0; j < C; j++) {
            visited[i][j] = false;
            path[i][j] = -1;
        }
    }
    
    int index = 0;
    int num = 0;
    vector<int> cnt[R*C];
    for (int i = 1; i < (R-1); i++) {
        for (int j = 1; j < (C-1); j++) {
            if (graph[i][j] == '.' && !visited[i][j]) {
                Point s = Point(i, j);
                int count = DFS(s, R, C, index);
                if (count > 0) {
                    cnt[count].push_back(index);
                    num += 1;
                }
                index += 1;
            }
        }
    }
    
    int delta = num - k;
    vector<int> indexs;
    int temp = 0;
    
    if (delta > 0) {
        for (int i = 0; i < R*C; i++) {
            if (!cnt[i].empty()) {
                for (int index : cnt[i]) {
                    temp += i;
                    indexs.push_back(index);
                    delta -= 1;
                    if (delta == 0) {
                        break;
                    }
                }
            }
            if (delta == 0) {
                break;
            }
        }
    }
    
    cout << temp << endl;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int p = path[i][j];
            if (needTranform(p, indexs)) {
                cout << '*';
            } else {
                cout << graph[i][j];
            }
            if (j == (C-1)) {
                cout << endl;
            }
        }
    }
    
    return 0;
}
