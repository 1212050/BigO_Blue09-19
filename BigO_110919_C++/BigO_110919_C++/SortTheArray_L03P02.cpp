//
//  SortTheArray_L03P02.cpp
//  BigO_110919_C++
//
//  Created by manhduydl on 9/18/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Segment {
    int i;
    int j;
};

int main() {
    
    int n;
    cin >> n;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    vector<int> sorted_v = v;
    sort(sorted_v.begin(), sorted_v.end());
    
    int L = -1, R = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] != sorted_v[i]) {
            if (L == -1) {
                L = i;
            }
            R = i;
        }
    }
    
    if (L == R) {
        cout << "No";
        return 0;
    }
    
    if (L == -1) {
        cout << "Yes" << endl;
        cout << 1 << " " << 1;
        return 0;
    }
    
    // reverse partial of v
    reverse(v.begin() + L, v.begin() + R + 1);
    
    for (int i = 0; i < n; i++) {
        if (v[i] != sorted_v[i]) {
            cout << "No";
            return 0;
        }
    }
    
    cout << "Yes" << endl;
    cout << L + 1 << " " << R + 1;
    
    return 0;
}

/*
 
 #include <iostream>
 #include <vector>
 #include <algorithm>
 using namespace std;

 int main() {
     int n;
     cin >> n;
     vector<int> a(n), sorted_a(n);

     for (int i = 0; i < n; i++) {
         cin >> a[i];
         sorted_a[i] = a[i];
     }

     sort(sorted_a.begin(), sorted_a.end());
     int l = 0, r = 0;

     for (int i = 0; i < n; i++) {
         if (a[i] != sorted_a[i]) {
             l = i;
             break;
         }
     }

     for (int i = n - 1; i >= 0; i--) {
         if (a[i] != sorted_a[i]) {
             r = i;
             break;
         }
     }

     for (int i = l, j = r; i < j; i++, j--) {
         swap(a[i], a[j]);
     }

     if (a != sorted_a) {
         cout << "no";
         return 0;
     }

     cout << "yes" << endl;
     cout << l + 1 << " " << r + 1;
     return 0;
 }
 */
