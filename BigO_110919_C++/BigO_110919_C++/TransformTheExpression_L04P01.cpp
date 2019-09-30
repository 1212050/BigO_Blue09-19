//
//  TransformTheExpression_L04P01.cpp
//  BigO_110919_C++
//
//  Created by manhduydl on 9/21/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

void transform(string expression) {
    
    stack<char> s;
    
    for (char symbol : expression) {
        if (isalpha(symbol)) {
            cout << symbol;
        } else if (symbol == ')') {
            cout << s.top();
            s.pop();
        } else if (symbol != '(') {
            s.push(symbol);
        }
    }
    
    cout << endl;
}

int main() {
    
    int n;
    cin >> n;
    
    string expression;
    for (int i = 0; i < n; i++) {
        cin >> expression;
        transform(expression);
    }
    
    return 0;
}

/*
 
 #include <iostream>
 #include <stack>
 #include <string>
 using namespace std;
  
 void transform(string expression) {
     stack<char> s;
      
     for (char symbol : expression) {
         if (isalpha(symbol)) {
             cout << symbol;
         }
         else if (symbol == ')') {
             cout << s.top();
             s.pop();
         }
         else if (symbol != '(') {
             s.push(symbol);
         }
     }
     cout << endl;
 }
  
 int main() {
     int t;
     string expression;
  
     cin >> t;
     for (int i = 0; i < t; i++) {
         cin >> expression;
         transform(expression);
     }
     return 0;
 }
 */
