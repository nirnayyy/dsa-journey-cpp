
/*
--------------------------------------------------
Problem: LeetCode 153
Topic: Binary Search
Day: 9/50
Difficulty: Medium

Time Complexity: O(log n)
Space Complexity: O(1)

Author: Nirnay Singh
--------------------------------------------------
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;

        while(left < right) {

            int mid = left + (right - left) / 2;

            if(nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }

        return nums[left];
    }
};

int main() {

    vector<int> nums = {4,5,6,7,0,1,2};

    Solution obj;

    cout << obj.findMin(nums);

    return 0;
}