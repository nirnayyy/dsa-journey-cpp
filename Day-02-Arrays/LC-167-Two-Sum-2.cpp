/*
--------------------------------------------------
Problem: LeetCode 167 - Two Sum II
Topic: Two Pointers
Day: 2/50
Difficulty: Medium

Approach:
1. Use two pointers
2. One pointer at start
3. One pointer at end
4. Compare sum with target
5. Move pointers accordingly

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
    vector<int> twoSum(vector<int>& numbers, int target) {

        int left = 0;
        int right = numbers.size() - 1;

        while(left < right) {

            int sum = numbers[left] + numbers[right];

            if(sum == target) {
                return {left + 1, right + 1};
            }

            else if(sum < target) {
                left++;
            }

            else {
                right--;
            }
        }

        return {};
    }
};

int main() {

    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    Solution obj;

    vector<int> ans = obj.twoSum(numbers, target);

    cout << "Input: [2,7,11,15]" << endl;
    cout << "Target: 9" << endl;

    cout << "Output: [";
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i];

        if(i != ans.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}