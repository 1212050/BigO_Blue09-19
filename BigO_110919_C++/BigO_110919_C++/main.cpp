//
//  main.cpp
//  BigO_110919_C++
//
//  Created by manhduydl on 9/11/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void bearAndGame() {
    int n;
    vector<int> v;
    int tempt;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tempt;
        v.push_back(tempt);
    }
    
    int threshHold = 0;
    for (int i = 0; i < v.size(); i++) {
        if (i == 0) {
            if (v[0] <= 15) {
                threshHold = v[0];
            } else {
                break;
            }
        } else {
            if (v[i] - v[i-1] <= 15) {
                threshHold = v[i];
            } else {
                break;
            }
        }
    }
    
    if (threshHold + 15 >= 90) {
        cout << 90;
    } else {
        cout << threshHold + 15;
    }
}

int getMinimumRotateCount(char startChar, char endChar) {
    
    int delta = abs(endChar - startChar);
    int result = 0;
    
    if (delta <= 13 ) {
        result = delta;
    } else {
        result = 26 - (delta);
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    
//    int n;
//    vector<int> v;
//    int tempt;
//
//    // input
//    cin >> n;
//    for (int i = 0; i < n; i++) {
//        cin >> tempt;
//        v.push_back(tempt);
//    }
//
//    if (v.size() == 1) {
//        if (v[0] == 0) {
//            cout << "NO";
//        } else {
//            cout << "YES";
//        }
//        return 0;
//    }
//
//    int count = 0;
//    for (int i = 0; i < v.size(); i++) {
//        if (v[i] == 0) {
//            count++;
//        }
//    }
//
//    if (count == 1) {
//        cout << "YES";
//    } else {
//        cout << "NO";
//    }
    
    
    
//    while(true) {
//        string s;
//        cin >> s;
//
//        int count = 0;
//        for (int i = 0; i < s.size(); i++) {
//            if (i == 0) {
//                count += getMinimumRotateCount('a', s[i]);
//            } else {
//                count += getMinimumRotateCount(s[i-1], s[i]);
//            }
//        }
//
//        cout << count << '\n';
//    }
    
    
    
    bearAndGame();
    return 0;
}
