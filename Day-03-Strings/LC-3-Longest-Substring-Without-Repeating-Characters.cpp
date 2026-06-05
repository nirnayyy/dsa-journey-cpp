/*
--------------------------------------------------
Problem: LeetCode 3 - Longest Substring Without Repeating Characters
Topic: Strings
Day: 3/50
Difficulty: Medium

Approach:
Use Sliding Window + Hash Set.
Expand window until duplicate found.
Shrink from left until valid again.

Time Complexity: O(n)
Space Complexity: O(n)

Author: Nirnay Singh
--------------------------------------------------
*/

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> st;

        int left = 0;
        int maxLen = 0;

        for(int right = 0; right < s.length(); right++) {

            while(st.count(s[right])) {

                st.erase(s[left]);
                left++;
            }

            st.insert(s[right]);

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main() {

    string s = "abcabcbb";

    Solution obj;

    cout << obj.lengthOfLongestSubstring(s);

    return 0;
}