/*
--------------------------------------------------
Problem: LeetCode 70 - Climbing Stairs
Topic: Recursion
Day: 18/50
--------------------------------------------------
*/

#include <iostream>

using namespace std;

class Solution {
public:

    int climbStairs(int n) {

        if(n <= 2)
            return n;

        return climbStairs(n-1)
             + climbStairs(n-2);
    }
};

int main() {

    Solution obj;

    cout << obj.climbStairs(5);

    return 0;
}