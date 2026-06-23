/*
--------------------------------------------------
Problem: LeetCode 875 - Koko Eating Bananas
Topic: Binary Search on Answer
Day: 21/50
Difficulty: Medium

Time Complexity: O(n log m)
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

    bool canEat(
        vector<int>& piles,
        int h,
        int speed) {

        long long hours = 0;

        for(int bananas : piles) {

            hours +=
            (bananas + speed - 1)
            / speed;
        }

        return hours <= h;
    }

    int minEatingSpeed(
        vector<int>& piles,
        int h) {

        int left = 1;

        int right =
        *max_element(
            piles.begin(),
            piles.end()
        );

        while(left < right) {

            int mid =
                left + (right-left)/2;

            if(canEat(
                piles,
                h,
                mid))

                right = mid;

            else

                left = mid + 1;
        }

        return left;
    }
};

int main() {

    vector<int> piles =
    {3,6,7,11};

    int h = 8;

    Solution obj;

    cout <<
    obj.minEatingSpeed(
        piles,
        h);

    return 0;
}