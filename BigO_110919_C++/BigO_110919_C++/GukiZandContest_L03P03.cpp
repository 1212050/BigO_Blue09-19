//
//  GukiZandContest_L03P03.cpp
//  BigO_110919_C++
//
//  Created by manhduydl on 9/20/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    vector<int> temp = v;
    sort(temp.begin(), temp.end(), greater<int>());
    
    vector<int> ctn(2000, 0);
    
    for (int i = 0; i < n; i++) {
        if (ctn[temp[i]] == 0) {
            ctn[temp[i]] = i+1;
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << ctn[v[i]] << " ";
    }
    
    return 0;
}

/*
 
 #include <iostream>
 #include <vector>
 #include <algorithm>
 using namespace std;
 const int MAX = 2005;

 int ranked[MAX];

 int main() {
     int n, rating;
     cin >> n;
     vector<int> ratings(n), sorted_ratings(n);

     for (int i = 0; i < n; i++) {
         cin >> rating;
         ratings[i] = sorted_ratings[i] = rating;
     }

     sort(sorted_ratings.begin(), sorted_ratings.end(), greater<int>());

     for (int i = 0; i < n; i++) {
         rating = sorted_ratings[i];
         
         if (!ranked[rating]) {
             ranked[rating] = i + 1;
         }
     }

     for (int& rating : ratings) {
         cout << ranked[rating] << " ";
     }

     return 0;
 }
 */
