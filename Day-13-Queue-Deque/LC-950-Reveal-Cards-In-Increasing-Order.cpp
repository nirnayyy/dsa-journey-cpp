/*
--------------------------------------------------
Problem: LeetCode 950 - Reveal Cards In Increasing Order
Topic: Deque
Day: 13/50
Difficulty: Medium

Time Complexity: O(n log n)
Space Complexity: O(n)

Author: Nirnay Singh
--------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(
        vector<int>& deck) {

        sort(deck.begin(),
             deck.end());

        deque<int> dq;

        for(int i = deck.size() - 1;
            i >= 0;
            i--) {

            if(!dq.empty()) {

                dq.push_front(
                    dq.back()
                );

                dq.pop_back();
            }

            dq.push_front(deck[i]);
        }

        return vector<int>(
            dq.begin(),
            dq.end()
        );
    }
};

int main() {

    vector<int> deck =
    {17,13,11,2,3,5,7};

    Solution obj;

    vector<int> ans =
        obj.deckRevealedIncreasing(deck);

    for(int x : ans)
        cout << x << " ";

    return 0;
}