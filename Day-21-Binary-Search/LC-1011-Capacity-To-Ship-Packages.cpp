/*
--------------------------------------------------
Problem: LeetCode 1011
Capacity To Ship Packages Within D Days

Topic: Binary Search on Answer
Day: 21/50
Difficulty: Medium

Time Complexity: O(n log(sum))
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

    bool canShip(
        vector<int>& weights,
        int days,
        int capacity) {

        int usedDays = 1;
        int currentWeight = 0;

        for(int weight : weights) {

            if(currentWeight +
               weight > capacity) {

                usedDays++;
                currentWeight = 0;
            }

            currentWeight += weight;
        }

        return usedDays <= days;
    }

    int shipWithinDays(
        vector<int>& weights,
        int days) {

        int left =
        *max_element(
            weights.begin(),
            weights.end()
        );

        int right = 0;

        for(int weight : weights)
            right += weight;

        while(left < right) {

            int mid =
                left + (right-left)/2;

            if(canShip(
                weights,
                days,
                mid))

                right = mid;

            else

                left = mid + 1;
        }

        return left;
    }
};

int main() {

    vector<int> weights =
    {1,2,3,4,5,6,7,8,9,10};

    int days = 5;

    Solution obj;

    cout <<
    obj.shipWithinDays(
        weights,
        days);

    return 0;
}