/*
--------------------------------------------------
Problem: LeetCode 1011
Capacity To Ship Packages Within D Days

Topic: Binary Search on Answer
Day: 10/50

Time Complexity: O(n log(sum))
Space Complexity: O(1)

Author: Nirnay Singh
--------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:

    bool canShip(vector<int>& weights,
                 int days,
                 int capacity) {

        int currentWeight = 0;
        int requiredDays = 1;

        for(int weight : weights) {

            if(currentWeight + weight > capacity) {

                requiredDays++;
                currentWeight = 0;
            }

            currentWeight += weight;
        }

        return requiredDays <= days;
    }

    int shipWithinDays(vector<int>& weights,
                       int days) {

        int left =
            *max_element(weights.begin(),
                         weights.end());

        int right =
            accumulate(weights.begin(),
                       weights.end(),
                       0);

        while(left < right) {

            int mid =
                left + (right - left) / 2;

            if(canShip(weights,
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

    cout << obj.shipWithinDays(weights,
                               days);

    return 0;
}