/*
--------------------------------------------------
Problem: LeetCode 1480 - Running Sum of 1D Array
Topic: Arrays
Day: 1/50
Difficulty: Easy

Approach:
- Traverse the array from index 1
- Add previous element to current element
- Store running sum in the same array

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
    vector<int> runningSum(vector<int>& nums) {

        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }

        return nums;
    }
};

int main() {

    vector<int> nums = {1, 2, 3, 4};

    Solution obj;
    vector<int> ans = obj.runningSum(nums);

    cout << "Input:  [1, 2, 3, 4]" << endl;

    cout << "Output: [";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];

        if (i != ans.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}