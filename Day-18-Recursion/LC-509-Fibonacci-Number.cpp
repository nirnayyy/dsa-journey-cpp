/*
--------------------------------------------------
Problem: LeetCode 509 - Fibonacci Number
Topic: Recursion
Day: 18/50
--------------------------------------------------
*/

#include <iostream>

using namespace std;

class Solution {
public:

    int fib(int n) {

        if(n <= 1)
            return n;

        return fib(n-1)
             + fib(n-2);
    }
};

int main() {

    Solution obj;

    cout << obj.fib(6);

    return 0;
}