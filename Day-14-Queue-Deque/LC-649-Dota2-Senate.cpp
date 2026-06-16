/*
--------------------------------------------------
Problem: LeetCode 649 - Dota2 Senate
Topic: Queue Simulation
Day: 14/50
Difficulty: Medium

Time Complexity: O(n)
Space Complexity: O(n)

Author: Nirnay Singh
--------------------------------------------------
*/

#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {

        queue<int> radiant;
        queue<int> dire;

        int n = senate.size();

        for(int i = 0; i < n; i++) {

            if(senate[i] == 'R')
                radiant.push(i);
            else
                dire.push(i);
        }

        while(!radiant.empty() &&
              !dire.empty()) {

            int r = radiant.front();
            radiant.pop();

            int d = dire.front();
            dire.pop();

            if(r < d) {

                radiant.push(r + n);
            }
            else {

                dire.push(d + n);
            }
        }

        return radiant.empty()
               ? "Dire"
               : "Radiant";
    }
};

int main() {

    string senate = "RDD";

    Solution obj;

    cout <<
    obj.predictPartyVictory(senate);

    return 0;
}