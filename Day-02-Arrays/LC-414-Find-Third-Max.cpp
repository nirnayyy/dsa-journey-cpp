/*
--------------------------------------------------
Problem: LeetCode 414 - Third Maximum Number
Topic: Arrays
Day: 2/50
Difficulty: Easy

Approach:
1. Sort the array
2. Traverse from right to left
3. Count distinct elements
4. Return third distinct maximum
5. If not present, return maximum

Time Complexity: O(n log n)
Space Complexity: O(1)

Author: Nirnay Singh
--------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int count = 1;

        for(int i = nums.size() - 2; i >= 0; i--) {

            if(nums[i] != nums[i + 1]) {

                count++;

                if(count == 3) {
                    return nums[i];
                }
            }
        }

        return nums.back();
    }
};

int main() {

    vector<int> nums = {2, 2, 3, 1};

    Solution obj;

    cout << "Input: [2, 2, 3, 1]" << endl;
    cout << "Output: " << obj.thirdMax(nums) << endl;

    return 0;
}