/*
--------------------------------------------------
Problem: LeetCode 125 - Valid Palindrome
Topic: Two Pointers
Day: 7/50
Difficulty: Easy

Time Complexity: O(n)
Space Complexity: O(1)

Author: Nirnay Singh
--------------------------------------------------
*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {

        int left = 0;
        int right = s.length() - 1;

        while(left < right) {

            while(left < right &&
                  !isalnum(s[left])) {
                left++;
            }

            while(left < right &&
                  !isalnum(s[right])) {
                right--;
            }

            if(tolower(s[left]) !=
               tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};

int main() {

    string s =
    "A man, a plan, a canal: Panama";

    Solution obj;

    cout << boolalpha
         << obj.isPalindrome(s);

    return 0;
}