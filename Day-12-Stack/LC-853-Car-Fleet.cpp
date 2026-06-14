/*
--------------------------------------------------
Problem: LeetCode 853 - Car Fleet
Topic: Stack + Sorting
Day: 12/50
Difficulty: Medium

Time Complexity: O(n log n)
Space Complexity: O(n)

Author: Nirnay Singh
--------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int carFleet(int target,
                 vector<int>& position,
                 vector<int>& speed) {

        vector<pair<int,double>> cars;

        int n = position.size();

        for(int i = 0; i < n; i++) {

            double time =
                (double)(target - position[i])
                / speed[i];

            cars.push_back(
                {position[i], time}
            );
        }

        sort(cars.rbegin(),
             cars.rend());

        int fleets = 0;

        double lastTime = 0;

        for(auto& car : cars) {

            double currentTime =
                car.second;

            if(currentTime > lastTime) {

                fleets++;
                lastTime = currentTime;
            }
        }

        return fleets;
    }
};

int main() {

    int target = 12;

    vector<int> position =
    {10,8,0,5,3};

    vector<int> speed =
    {2,4,1,1,3};

    Solution obj;

    cout << obj.carFleet(
                target,
                position,
                speed);

    return 0;
}