//
//  FerryLoading_L04P06.cpp
//  BigO_110919_C++
//
//  Created by manhduydl on 9/24/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Car {
    int index;
    int time;
};

int main() {
    int testCases;
    cin >> testCases;
    int count = 0;
    
    queue<Car> qLeft;
    queue<Car> qRight;
    
    // 0:left
    // 1:right
    queue<Car> qSide[2] = {qLeft, qRight};
    
    while (true) {
        int N, T, M;
        cin >> N >> T >> M;
        
        for (int i = 0; i < M; i++) {
            int time;
            string bank;
            cin >> time >> bank;
            if (bank == "left") {
                qSide[0].push({i, time});
            } else {
                qSide[1].push({i, time});
            }
        }
        
        vector<int> result(M);
        int curBank = 0;
        int curTime = 0;
        
        while (true) {
            
            int leftTime = INT32_MAX;
            int rightTime = INT32_MAX;
            if (!qSide[0].empty()) {
                leftTime = qSide[0].front().time;
            }
            if (!qSide[1].empty()) {
                rightTime = qSide[1].front().time;
            }
            if (curTime < leftTime && curTime < rightTime) {
                curTime = min(leftTime, rightTime);
            }
            
            int carried = 0;
            if (!qSide[curBank].empty()) {
                while (qSide[curBank].front().time <= curTime && carried < N) {
                    result[qSide[curBank].front().index] = curTime + T;
                    qSide[curBank].pop();
                    carried++;
                    if (qSide[curBank].empty()) {
                        break;
                    }
                }
            }
            curBank = 1 - curBank;
            curTime += T;
            
            if (qSide[0].empty() && qSide[1].empty()) {
                break;
            }
        }
        
        for (int i : result) {
            cout << i << endl;
        }
        count++;
        if (count < testCases) {
            cout << endl;
        } else {
            break;
        }
    }
    
    return 0;
}

/* Solution
 
 
 struct Car {
     int id, arriveTime;
 };
  
 int main() {
     int n, t, m, Q;
     int res[MAX];
     cin >> Q;
      
     while (Q--) {
         queue<Car> qSide[2];
         int arrived;
         string atBank;
          
         cin >> n >> t >> m;
          
         for (int i = 1; i <= m; i++) {
             cin >> arrived >> atBank;
              
             if (atBank == "left") {
                 qSide[0].push((Car) {i, arrived});
             }
             else {
                 qSide[1].push((Car) {i, arrived});
             }
         }
          
         int curSide = 0, curTime = 0, nextTime;
         int waiting = !qSide[0].empty() + !qSide[1].empty();
          
         while (waiting) {
             if (waiting == 1) {
                 nextTime = (qSide[0].empty() ? qSide[1].front().arriveTime : qSide[0].front().arriveTime);
             }
             else {
                 nextTime = min(qSide[0].front().arriveTime, qSide[1].front().arriveTime);
             }
              
             curTime = max(curTime, nextTime);
             int carried = 0;
              
             while (!qSide[curSide].empty()) {
                 Car car = qSide[curSide].front();
                 if (car.arriveTime <= curTime && carried < n) {
                     res[car.id] = curTime + t;
                     carried++;
                     qSide[curSide].pop();
                 }
                 else {
                     break;
                 }
             }
              
             curTime += t;
             curSide = 1 - curSide;
             waiting = !qSide[0].empty() + !qSide[1].empty();
         }
          
         for (int i = 1; i <= m; i++) {
             cout << res[i] << endl;
         }
          
         if (Q) {
             cout << endl;
         }
     }
     return 0;
 }
 */
