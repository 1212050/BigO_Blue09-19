//
//  StreetParadeL04P02.cpp
//  BigO_110919_C++
//
//  Created by manhduydl on 9/21/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    
    
    int n;
    cin >> n;
    while (n > 0) {
        vector<int> mobiles(n);
        for (int i = 0; i < n; i++) {
            cin >> mobiles[i];
        }
        
        stack<int> sideStreet;
        int need = 1;
        bool state = true;
        
        for (int i = 0; i < n; i++) {
            while (!sideStreet.empty() && sideStreet.top() == need) {
                need++;
                sideStreet.pop();
            }
            
            if (mobiles[i] == need) {
                need++;
            } else if (!sideStreet.empty() && sideStreet.top() < mobiles[i]) {
                state = false;
                break;
            } else {
                sideStreet.push(mobiles[i]);
            }
        }
        
        if (state == true) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
        
        cin >> n;
    }
    
    return 0;
}

/*
 
 #include <iostream>
 #include <stack>
 using namespace std;
 const int MAX = 1005;
  
 int main() {
     int n;
     int trucks[MAX];
     stack<int> side_trucks;
  
     while (true) {
         cin >> n;
         if (n == 0) {
             break;
         }
      
         for (int i = 0; i < n; i++) {
             cin >> trucks[i];
         }
  
         int ordering = 1;
         int i = 0;
          
         while (i < n) {
             if (trucks[i] == ordering) {
                 i++;
                 ordering++;
             }
             else if (!side_trucks.empty() && side_trucks.top() == ordering) {
                 ordering++;
                 side_trucks.pop();
             }
             else {
                 side_trucks.push(trucks[i]);
                 i++;
             }
         }
  
         while (!side_trucks.empty() && side_trucks.top() == ordering) {
             ordering++;
             side_trucks.pop();
         }
  
         cout << (ordering == n + 1 ? "yes" : "no") << endl;
         while (!side_trucks.empty()) {
             side_trucks.pop();
         }
     }
     return 0;
 }
 */
