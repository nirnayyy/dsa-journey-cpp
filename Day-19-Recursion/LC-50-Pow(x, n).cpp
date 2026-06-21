/*
--------------------------------------------------
Problem: LeetCode 50 - Pow(x,n)
Topic: Recursion + Divide & Conquer
Day: 19/50
--------------------------------------------------
*/

#include <iostream>

using namespace std;

class Solution {
public:

    double power(
        double x,
        long long n) {

        if(n == 0)
            return 1;

        double half =
            power(x, n / 2);

        if(n % 2 == 0)
            return half * half;

        return half * half * x;
    }

    double myPow(
        double x,
        int n) {

        long long N = n;

        if(N < 0) {

            x = 1 / x;
            N = -N;
        }

        return power(x, N);
    }
};

int main() {

    Solution obj;

    cout << obj.myPow(2, 10);

    return 0;
}