//
//  Meeting.cpp
//  FloydWarshall
//
//  Created by manhduydl on 10/17/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 30
#define INF 1e9

vector<vector<int>> yGraph;
vector<vector<int>> yDist;

vector<vector<int>> mGraph;
vector<vector<int>> mDist;

bool floydWarshall(vector<vector<int>> &yDist, vector<vector<int>> &mDist) {
    
    for (int k = 0; k < MAX; k++) {
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                if (mDist[i][j] > mDist[i][k] + mDist[k][j]) {
                    mDist[i][j] = mDist[i][k] + mDist[k][j];
                }
                if (yDist[i][j] > yDist[i][k] + yDist[k][j]) {
                    yDist[i][j] = yDist[i][k] + yDist[k][j];
                }
            }
        }
    }
    
    for (int i = 0; i < MAX; i++) {
        if (mDist[i][i] < 0 || yDist[i][i] < 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    
    while (true) {
        int N;
        cin >> N;
        
        if (N == 0) {
            return 0;
        }
        
        yGraph = vector<vector<int>>(MAX, vector<int>(MAX, INF));
        yDist = vector<vector<int>>(MAX, vector<int>(MAX, INF));
        mGraph = vector<vector<int>>(MAX, vector<int>(MAX, INF));
        mDist = vector<vector<int>>(MAX, vector<int>(MAX, INF));
        
        for (int i = 0; i < MAX; i++) {
            yGraph[i][i] = 0;
            mGraph[i][i] = 0;
        }
        
        for (int i = 0; i < N; i++) {
            char age, direct, X, Y;
            int w;
            cin >> age >> direct >> X >> Y >> w;
            int u = X - 'A';
            int v = Y - 'A';
            if (age == 'Y') {
                yGraph[u][v] = min(w, yGraph[u][v]);
                if (direct == 'B') {
                    yGraph[v][u] = min(w, yGraph[v][u]);
                }
            }
            else {
                mGraph[u][v] = min(w, mGraph[u][v]);
                if (direct == 'B') {
                    mGraph[v][u] = min(w, mGraph[v][u]);
                }
            }
        }
        
        for (int i = 0; i < MAX; i++) {
            yGraph[i][i] = 0;
            mGraph[i][i] = 0;
        }
        
        yDist = yGraph;
        mDist = mGraph;
        
        floydWarshall(yDist, mDist);
        
        char c1, c2;
        cin >> c1 >> c2;
        int yStart = c1 - 'A';
        int mStart = c2 - 'A';
        
        vector<char> result;
        int value = INF;

        for (int i = 0; i < 26; i++) {
            char k = 'A' + i;
            int dist = yDist[yStart][i] + mDist[mStart][i];
            if (dist == value && dist != INF) {
                result.push_back(k);
            }
            else if (dist < value) {
                result.clear();
                result.push_back(k);
                value = dist;
            }
        }
        
        if (value == INF) {
            cout << "You will never meet." << endl;
            continue;
        }
        cout << value << " ";
        for (char c : result) {
            cout << c;
            if (c != result.back()) {
                cout << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
