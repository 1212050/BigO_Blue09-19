//
//  PashaandTea_L03P04.cpp
//  BigO_110919_C++
//
//  Created by manhduydl on 9/20/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    
    int n, w;
    cin >> n >> w;
    
    vector<int> A(2*n);
    for (int i = 0; i < 2*n; i++) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    double minW = A[0];
    double minM = A[n];
    
    double maxa = min(minW, minM/2);
    
    double maxw = n*maxa + n*2*maxa;
    
    cout << setprecision(9) << min(maxw, 1.0 * w);
    
    return 0;
}

/*
 
 #include <iostream>
 #include <vector>
 #include <algorithm>
 #include <iomanip>
 using namespace std;

 int main() {
     int n, w;
     cin >> n >> w;
     vector<int> cups(n * 2);
     
     for (int i = 0; i < n * 2; i++) {
         cin >> cups[i];
     }
     
     sort(cups.begin(), cups.end());

     double m = min(1.0 * cups[0], 1.0 * cups[n] / 2);
     double total = 3 * m * n;
     cout << setprecision(9) << min(total, 1.0 * w);
     return 0;
 }
 */
