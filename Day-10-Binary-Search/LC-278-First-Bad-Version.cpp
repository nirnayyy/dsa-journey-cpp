/*
--------------------------------------------------
Problem: LeetCode 278 - First Bad Version
Topic: Binary Search
Day: 10/50
Difficulty: Easy

Time Complexity: O(log n)
Space Complexity: O(1)

Author: Nirnay Singh
--------------------------------------------------
*/

#include <iostream>

using namespace std;

int badVersion = 4;

bool isBadVersion(int version) {
    return version >= badVersion;
}

class Solution {
public:
    int firstBadVersion(int n) {

        int left = 1;
        int right = n;

        while(left < right) {

            int mid =
                left + (right - left) / 2;

            if(isBadVersion(mid))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};

int main() {

    int n = 5;

    Solution obj;

    cout << obj.firstBadVersion(n);

    return 0;
}