/*
Problem: LeetCode 1 - Two Sum
Topic: Arrays + Hashing
Day: 1
Difficulty: Easy

Approach:
1. Use Hash Map
2. Store visited numbers
3. Find complement

Time Complexity: O(n)
Space Complexity: O(n)
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++){

            int need = target - nums[i];

            if(mp.find(need)!=mp.end())
                return {mp[need],i};

            mp[nums[i]]=i;
        }

        return {};
    }
};