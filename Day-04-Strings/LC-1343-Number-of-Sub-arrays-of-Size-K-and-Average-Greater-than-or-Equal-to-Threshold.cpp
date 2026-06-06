/*
--------------------------------------------------
Problem: LeetCode 1343
Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold

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
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {

        int target = k * threshold;
        int windowSum = 0;

        for(int i = 0; i < k; i++) {
            windowSum += arr[i];
        }

        int count = 0;

        if(windowSum >= target)
            count++;

        for(int i = k; i < arr.size(); i++) {

            windowSum =
                windowSum
                - arr[i - k]
                + arr[i];

            if(windowSum >= target)
                count++;
        }

        return count;
    }
};

int main() {

    vector<int> arr = {2,2,2,2,5,5,5,8};
    int k = 3;
    int threshold = 4;

    Solution obj;

    cout << obj.numOfSubarrays(arr, k, threshold);

    return 0;
}