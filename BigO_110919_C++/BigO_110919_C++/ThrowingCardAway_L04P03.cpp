//
//  ThrowingCardAway_L04P03.cpp
//  BigO_110919_C++
//
//  Created by manhduydl on 9/23/19.
//  Copyright © 2019 manhduydl. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    while (n > 0) {
        queue<int> deck;
        for (int i = 1; i <= n; i++) {
            deck.push(i);
        }
        
        vector<int> discards;
        while (deck.size() > 1) {
            discards.push_back(deck.front());
            deck.pop();
            
            deck.push(deck.front());
            deck.pop();
        }
        
        cout << "Discarded cards:";
        for (int item : discards) {
            cout << " " << item;
            if (item != discards.back()) {
                cout << ",";
            }
        }
        cout << endl << "Remaining card: " << deck.front() << endl;
        
        cin >> n;
    }
    
    return 0;
}

/* Solution
 
 #include <iostream>
 #include <vector>
 #include <queue>
 using namespace std;
  
 int main() {
     int n;
     queue<int> deck;
     vector<int> discarded_cards;
  
     while (true) {
         cin >> n;
         if (n == 0) {
             break;
         }
  
         for (int i = 1; i <= n; i++) {
             deck.push(i);
         }
  
         while (deck.size() >= 2) {
             discarded_cards.push_back(deck.front());
             deck.pop();
             deck.push(deck.front());
             deck.pop();
         }
  
         cout << "Discarded cards:";
         for (int i = 0; i < n - 1; i++) {
             if (i != 0) {
                 cout << ",";
             }
             cout << " " << discarded_cards[i];
         }
         cout << endl;
         cout << "Remaining card: " << deck.front() << endl;
          
         deck.pop();
         discarded_cards.clear();
     }
     return 0;
 }
 */
