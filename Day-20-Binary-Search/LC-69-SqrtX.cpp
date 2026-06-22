/*
--------------------------------------------------
Problem: LeetCode 69 - Sqrt(x)
Topic: Binary Search on Answer
Day: 20/50
Difficulty: Easy

Time Complexity: O(log n)
Space Complexity: O(1)

Author: Nirnay Singh
--------------------------------------------------
*/

#include <iostream>

using namespace std;

class Solution {
public:

    int mySqrt(int x) {

        long long left = 0;
        long long right = x;

        int ans = 0;

        while(left <= right) {

            long long mid =
                left + (right - left) / 2;

            if(mid * mid <= x) {

                ans = mid;
                left = mid + 1;
            }
            else {

                right = mid - 1;
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    cout << obj.mySqrt(8);

    return 0;
}