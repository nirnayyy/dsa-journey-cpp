/*
--------------------------------------------------
Problem: LeetCode 242 - Valid Anagram
Topic: Strings
Day: 3/50
Difficulty: Easy

Approach:
Sort both strings and compare.

Time Complexity: O(n log n)
Space Complexity: O(1)

Author: Nirnay Singh
--------------------------------------------------
*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};

int main() {

    string s = "anagram";
    string t = "nagaram";

    Solution obj;

    cout << boolalpha << obj.isAnagram(s, t);

    return 0;
}