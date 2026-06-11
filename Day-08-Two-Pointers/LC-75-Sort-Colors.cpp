/*
--------------------------------------------------
Problem: LeetCode 75 - Sort Colors
Topic: Two Pointers
Day: 8/50
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
    void sortColors(vector<int>& nums) {

        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while(mid <= high) {

            if(nums[mid] == 0) {

                swap(nums[low], nums[mid]);

                low++;
                mid++;
            }

            else if(nums[mid] == 1) {

                mid++;
            }

            else {

                swap(nums[mid], nums[high]);

                high--;
            }
        }
    }
};

int main() {

    vector<int> nums = {2,0,2,1,1,0};

    Solution obj;

    obj.sortColors(nums);

    for(int num : nums)
        cout << num << " ";

    return 0;
}