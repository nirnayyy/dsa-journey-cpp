/*
--------------------------------------------------
Problem: LeetCode 387 - First Unique Character in a String
Topic: Strings
Day: 3/50
Difficulty: Easy

Approach:
Count frequency of characters.
Return first index whose frequency is 1.

Time Complexity: O(n)
Space Complexity: O(1)

Author: Nirnay Singh
--------------------------------------------------
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {

        int freq[26] = {0};

        for(char c : s) {
            freq[c - 'a']++;
        }

        for(int i = 0; i < s.length(); i++) {

            if(freq[s[i] - 'a'] == 1)
                return i;
        }

        return -1;
    }
};

int main() {

    string s = "loveleetcode";

    Solution obj;

    cout << obj.firstUniqChar(s);

    return 0;
}