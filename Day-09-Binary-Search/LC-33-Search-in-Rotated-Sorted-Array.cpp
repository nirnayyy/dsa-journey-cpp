/*
--------------------------------------------------
Problem: LeetCode 33
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
    int search(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;

        while(left <= right) {

            int mid = left + (right - left) / 2;

            if(nums[mid] == target)
                return mid;

            if(nums[left] <= nums[mid]) {

                if(target >= nums[left] &&
                   target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else {

                if(target > nums[mid] &&
                   target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        return -1;
    }
};

int main() {

    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;

    Solution obj;

    cout << obj.search(nums, target);

    return 0;
}