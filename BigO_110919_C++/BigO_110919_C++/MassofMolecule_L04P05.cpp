//
//  MassofMolecule_L04P05.cpp
//  BigO_110919_C++
//
//  Created by manhduydl on 9/24/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    
    string formular;
    cin >> formular;
    
    stack<int> s;
    for (char c : formular) {
        if (c == '(') {
            s.push(0);
        }
        else if (isalpha(c)) {
            if (c == 'C') {
                s.push(12);
            } else if (c == 'H') {
                s.push(1);
            } else if (c == 'O') {
                s.push(16);
            }
        }
        else if (isdigit(c)) {
            int temp = s.top() * ((int)c - '0');
            s.pop();
            s.push(temp);
        }
        else if (c == ')') {
            int temp = 0;
            while (s.top() > 0) {
                temp += s.top();
                s.pop();
            }
            s.pop();
            s.push(temp);
        }
    }
    
    int sum = 0;
    while (s.size() > 0) {
        sum += s.top();
        s.pop();
    }
    
    cout << sum;
    
    return 0;
}

/* Solution
 
 #include <iostream>
 #include <stack>
 #include <string>
 using namespace std;
  
 int mass(char c) {
     return c == 'H' ? 1 : (c == 'C' ? 12 : 16);
 }
  
 int main() {
     string s;
     cin >> s;
  
     stack<int> atom;
     int w, mol;
  
     for (char c : s) {
         if (isalpha(c)) {
             atom.push(mass(c));
         }
         else if (isdigit(c)) {
             mol = atom.top() * (c - '0');
             atom.pop();
             atom.push(mol);
         }
         else if (c == '(') {
             atom.push(-1);
         }
         else if (c == ')') {
             w = 0;
             while (atom.top() != -1) {
                 w += atom.top();
                 atom.pop();
             }
             atom.pop();
             atom.push(w);
         }
     }
      
     int sum = 0;
     while (!atom.empty()) {
         sum += atom.top();
         atom.pop();
     }
  
     cout << sum;
     return 0;
 }
 */
