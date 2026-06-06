/*
--------------------------------------------------
Problem: LeetCode 209
Minimum Size Subarray Sum

Topic: Sliding Window
Day: 4/50
Difficulty: Medium

Time Complexity: O(n)
Space Complexity: O(1)

Author: Nirnay Singh
--------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int left = 0;
        int sum = 0;
        int minLen = INT_MAX;

        for(int right = 0; right < nums.size(); right++) {

            sum += nums[right];

            while(sum >= target) {

                minLen = min(minLen,
                             right - left + 1);

                sum -= nums[left];
                left++;
            }
        }

        if(minLen == INT_MAX)
            return 0;

        return minLen;
    }
};

int main() {

    int target = 7;
    vector<int> nums = {2,3,1,2,4,3};

    Solution obj;

    cout << obj.minSubArrayLen(target, nums);

    return 0;
}