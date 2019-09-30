//
//  Devu.cpp
//  BigO_110919_C++
//
//  Created by manhduydl on 9/18/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long selfLearing(vector<int> &subjects, int x) {
    sort(subjects.begin(), subjects.end());
    
    long long min_time = 0;
    for (int subject : subjects) {
        min_time += 1LL * subject * x;
        if (x > 1) {
            x--;
        }
    }
    return min_time;
}

int main() {
    
    int n, x;
    cin >> n >> x;
    vector<int> subjects(n);
    for (int i = 0; i < n; i++) {
        cin >> subjects[i];
    }
    long long result = selfLearing(subjects, x);
    cout << result;
    
    return 0;
}

/*
 
 #include <iostream>
 #include <vector>
 #include <algorithm>
 using namespace std;

 int main() {
     int n, x;
     cin >> n >> x;
     vector<int> c(n);
     
     for (int i = 0; i < n; i++) {
         cin >> c[i];
     }
     
     sort(c.begin(), c.end());
     
     long long min_time = 0;
     
     for (int chapters : c) {
         min_time += 1LL * chapters * x;
         if (x > 1) {
             x--;
         }
     }
     
     cout << min_time;
     return 0;
 }
 */
