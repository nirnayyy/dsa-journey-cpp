/*
--------------------------------------------------
Problem: LeetCode 1493
Longest Subarray of 1's After Deleting One Element

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

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int left = 0;
        int zeros = 0;
        int maxLen = 0;

        for(int right = 0; right < nums.size(); right++) {

            if(nums[right] == 0)
                zeros++;

            while(zeros > 1) {

                if(nums[left] == 0)
                    zeros--;

                left++;
            }

            maxLen = max(maxLen, right - left);
        }

        return maxLen;
    }
};

int main() {

    vector<int> nums = {1,1,0,1};

    Solution obj;

    cout << obj.longestSubarray(nums);

    return 0;
}