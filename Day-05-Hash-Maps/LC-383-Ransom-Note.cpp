/*
--------------------------------------------------
Problem: LeetCode 383 - Ransom Note
Topic: Hash Maps
Day: 5/50
Difficulty: Easy

Approach:
Count frequency of magazine characters.
Use those characters to construct ransom note.

Time Complexity: O(n + m)
Space Complexity: O(1)

Author: Nirnay Singh
--------------------------------------------------
*/

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        unordered_map<char, int> freq;

        for(char c : magazine) {
            freq[c]++;
        }

        for(char c : ransomNote) {

            if(freq[c] == 0)
                return false;

            freq[c]--;
        }

        return true;
    }
};

int main() {

    string ransomNote = "aa";
    string magazine = "aab";

    Solution obj;

    cout << boolalpha
         << obj.canConstruct(ransomNote, magazine);

    return 0;
}