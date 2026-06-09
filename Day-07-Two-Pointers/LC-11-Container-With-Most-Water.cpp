/*
--------------------------------------------------
Problem: LeetCode 11 - Container With Most Water
Topic: Two Pointers
Day: 7/50
Difficulty: Medium

Time Complexity: O(n)
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
    int maxArea(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;

        int maxWater = 0;

        while(left < right) {

            int width = right - left;

            int currentHeight =
                min(height[left],
                    height[right]);

            int area =
                width * currentHeight;

            maxWater =
                max(maxWater, area);

            if(height[left]
               < height[right]) {

                left++;
            }
            else {

                right--;
            }
        }

        return maxWater;
    }
};

int main() {

    vector<int> height =
    {1,8,6,2,5,4,8,3,7};

    Solution obj;

    cout << obj.maxArea(height);

    return 0;
}