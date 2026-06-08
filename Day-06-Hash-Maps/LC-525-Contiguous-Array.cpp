/*
--------------------------------------------------
Problem: LeetCode 525 - Contiguous Array
Topic: Hash Maps + Prefix Sum
Day: 6/50
Difficulty: Medium

Time Complexity: O(n)
Space Complexity: O(n)

Author: Nirnay Singh
--------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        unordered_map<int,int> mp;

        mp[0] = -1;

        int sum = 0;
        int maxLen = 0;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] == 0)
                sum += -1;
            else
                sum += 1;

            if(mp.count(sum)) {

                maxLen =
                    max(maxLen,
                        i - mp[sum]);
            }
            else {

                mp[sum] = i;
            }
        }

        return maxLen;
    }
};

int main() {

    vector<int> nums = {0,1,0};

    Solution obj;

    cout << obj.findMaxLength(nums);

    return 0;
}