/*
--------------------------------------------------
Problem: LeetCode 643 - Maximum Average Subarray I
Topic: Sliding Window
Day: 2/50
Difficulty: Easy

Approach:
1. Calculate first window sum
2. Slide window one step at a time
3. Remove left element
4. Add right element
5. Track maximum sum

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
    double findMaxAverage(vector<int>& nums, int k) {

        int windowSum = 0;

        for(int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        int maxSum = windowSum;

        for(int i = k; i < nums.size(); i++) {

            windowSum = windowSum - nums[i - k] + nums[i];

            maxSum = max(maxSum, windowSum);
        }

        return (double)maxSum / k;
    }
};

int main() {

    vector<int> nums = {1,12,-5,-6,50,3};
    int k = 4;

    Solution obj;

    cout << "Maximum Average = "
         << obj.findMaxAverage(nums, k);

    return 0;
}