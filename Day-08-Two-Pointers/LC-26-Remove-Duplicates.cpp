/*
--------------------------------------------------
Problem: LeetCode 26 - Remove Duplicates from Sorted Array
Topic: Two Pointers
Day: 8/50
Difficulty: Easy

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
    int removeDuplicates(vector<int>& nums) {

        int i = 0;

        for(int j = 1; j < nums.size(); j++) {

            if(nums[i] != nums[j]) {

                i++;
                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};

int main() {

    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    Solution obj;

    int k = obj.removeDuplicates(nums);

    cout << "Unique Count = " << k << endl;

    cout << "Array: ";

    for(int i = 0; i < k; i++)
        cout << nums[i] << " ";

    return 0;
}