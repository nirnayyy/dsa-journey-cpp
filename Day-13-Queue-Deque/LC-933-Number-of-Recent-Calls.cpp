/*
--------------------------------------------------
Problem: LeetCode 933 - Number of Recent Calls
Topic: Queue
Day: 13/50
Difficulty: Easy

Time Complexity: O(1) Amortized
Space Complexity: O(n)

Author: Nirnay Singh
--------------------------------------------------
*/

#include <iostream>
#include <queue>

using namespace std;

class RecentCounter {
private:
    queue<int> q;

public:
    int ping(int t) {

        q.push(t);

        while(!q.empty() &&
              q.front() < t - 3000) {

            q.pop();
        }

        return q.size();
    }
};

int main() {

    RecentCounter rc;

    cout << rc.ping(1) << endl;
    cout << rc.ping(100) << endl;
    cout << rc.ping(3001) << endl;
    cout << rc.ping(3002) << endl;

    return 0;
}