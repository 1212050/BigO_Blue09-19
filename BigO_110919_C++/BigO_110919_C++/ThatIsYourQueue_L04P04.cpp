//
//  ThatIsYourQueue_L04P04.cpp
//  BigO_110919_C++
//
//  Created by manhduydl on 9/23/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int main() {
    
    int P, C, index = 1;
    cin >> P >> C;
    while (P > 0 && C > 0) {
        cout << "Case " << index << ":" << endl;
        stack<int> priority;
        int next = 1;
        for (int i = 0; i < C; i++) {
            char command;
            cin >> command;
            if (command == 'N') {
                if (priority.empty()) {
                    cout << next << endl;
                    next++;
                } else {
                    cout << priority.top() << endl;
                    priority.pop();
                }
            } else if (command == 'E') {
                int temp;
                cin >> temp;
                priority.push(temp);
            }
        }
        
        cin >> P >> C;
    }
    
    return 0;
}
