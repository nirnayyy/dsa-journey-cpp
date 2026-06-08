/*
--------------------------------------------------
Problem: LeetCode 560 - Subarray Sum Equals K
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
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> mp;

        mp[0] = 1;

        int sum = 0;
        int count = 0;

        for(int num : nums) {

            sum += num;

            if(mp.count(sum - k))
                count += mp[sum - k];

            mp[sum]++;
        }

        return count;
    }
};

int main() {

    vector<int> nums = {1,1,1};
    int k = 2;

    Solution obj;

    cout << obj.subarraySum(nums, k);

    return 0;
}