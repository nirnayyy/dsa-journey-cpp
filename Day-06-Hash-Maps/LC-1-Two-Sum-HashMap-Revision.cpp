/*
--------------------------------------------------
Problem: LeetCode 1 - Two Sum
Topic: Hash Maps
Day: 6/50
Difficulty: Easy

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
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> mp;

        for(int i = 0; i < nums.size(); i++) {

            int complement = target - nums[i];

            if(mp.count(complement)) {

                return {
                    mp[complement],
                    i
                };
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};

int main() {

    vector<int> nums = {2,7,11,15};
    int target = 9;

    Solution obj;

    vector<int> ans =
        obj.twoSum(nums, target);

    cout << ans[0]
         << " "
         << ans[1];

    return 0;
}