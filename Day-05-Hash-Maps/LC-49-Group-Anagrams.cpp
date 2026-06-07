/*
--------------------------------------------------
Problem: LeetCode 49 - Group Anagrams
Topic: Hash Maps
Day: 5/50
Difficulty: Medium

Approach:
Sort each word.
Use sorted word as key in hash map.

Time Complexity: O(n * k log k)
Space Complexity: O(n)

Author: Nirnay Singh
--------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for(string word : strs) {

            string key = word;

            sort(key.begin(), key.end());

            mp[key].push_back(word);
        }

        vector<vector<string>> result;

        for(auto pair : mp) {
            result.push_back(pair.second);
        }

        return result;
    }
};

int main() {

    vector<string> strs =
    {"eat","tea","tan","ate","nat","bat"};

    Solution obj;

    vector<vector<string>> ans =
        obj.groupAnagrams(strs);

    for(auto group : ans) {

        cout << "[ ";

        for(string word : group)
            cout << word << " ";

        cout << "]" << endl;
    }

    return 0;
}