//
//  VitalyAndStrings.cpp
//  BigO_110919_C++
//
//  Created by manhduydl on 9/11/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    string S;
    string T;
    cin >> S >> T;

    unsigned long n = S.length();
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (S[i] < T[i]) {
            index = i;
            break;
        }
    }

    if (index == n - 1) {
        if ((T[index] - S[index]) > 1) {
            char newChar = S[index] + 1;
            string newString = S.substr(0, n-1);
            newString.push_back(newChar);
            cout << newString;
            return 0;
        } else {
            cout << "No such string";
            return 0;
        }
    }
    // Find with S
    for (int i = index + 1; i < n; i++) {
        if (S[i] < 'z') {
            // S[i]++ and return
            string newLetter = string(1, S[i] + 1);
            S.replace(i, 1, newLetter);
            cout << S;
            return 0;
        }
    }
    
    //Find with T
    for (int i = index + 1; i < n; i++) {
        if (T[i] > 'a') {
            // T[i]-- and return
            string newLetter = string(1, T[i] - 1);
            T.replace(i, 1, newLetter);
            cout << T;
            return 0;
        }
    }
    
    cout << "No such string";
    
    return 0;
}
