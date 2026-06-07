/*
--------------------------------------------------
Problem: LeetCode 128 - Longest Consecutive Sequence
Topic: Hash Maps / Hash Set
Day: 5/50
Difficulty: Medium

Approach:
Store numbers in Hash Set.
Start sequence only when previous number
does not exist.

Time Complexity: O(n)
Space Complexity: O(n)

Author: Nirnay Singh
--------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st(
            nums.begin(),
            nums.end()
        );

        int longest = 0;

        for(int num : st) {

            if(!st.count(num - 1)) {

                int current = num;
                int length = 1;

                while(st.count(current + 1)) {

                    current++;
                    length++;
                }

                longest =
                    max(longest, length);
            }
        }

        return longest;
    }
};

int main() {

    vector<int> nums =
    {100,4,200,1,3,2};

    Solution obj;

    cout << obj.longestConsecutive(nums);

    return 0;
}