//
//  DemoSort.cpp
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

struct Student {
    int id;
    double score;
    
    bool operator < (const Student B) const {
        if (score > B.score) {
            return true;
        }
        return false;
    }
};

bool myCompFunction(int i, int j) { return i > j; };

int main() {
    
    vector<Student> list_student;
    list_student.push_back({100, 8.5});
    list_student.push_back({101, 7.5});
    list_student.push_back({102, 9});
    list_student.push_back({103, 8});
    
    sort(list_student.begin(), list_student.end());
    
    for (Student &s : list_student) {
        cout << s.id << " " << s.score << endl;
    }
    
    getchar();
    return 0;
}
