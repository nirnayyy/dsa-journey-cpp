/*
--------------------------------------------------
Problem: LeetCode 344 - Reverse String
Topic: Recursion
Day: 18/50
--------------------------------------------------
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void solve(
        vector<char>& s,
        int left,
        int right) {

        if(left >= right)
            return;

        swap(
            s[left],
            s[right]
        );

        solve(
            s,
            left + 1,
            right - 1
        );
    }

    void reverseString(
        vector<char>& s) {

        solve(
            s,
            0,
            s.size()-1
        );
    }
};

int main() {

    vector<char> s =
    {'h','e','l','l','o'};

    Solution obj;

    obj.reverseString(s);

    for(char c : s)
        cout << c << " ";

    return 0;
}