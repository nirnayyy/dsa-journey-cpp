/*
--------------------------------------------------
Problem: LeetCode 739 - Daily Temperatures
Topic: Monotonic Stack
Day: 11/50
Difficulty: Medium

Time Complexity: O(n)
Space Complexity: O(n)

Author: Nirnay Singh
--------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(
        vector<int>& temperatures) {

        int n = temperatures.size();

        vector<int> ans(n, 0);

        stack<int> st;

        for(int i = 0; i < n; i++) {

            while(!st.empty() &&
                  temperatures[i] >
                  temperatures[st.top()]) {

                int index = st.top();
                st.pop();

                ans[index] = i - index;
            }

            st.push(i);
        }

        return ans;
    }
};

int main() {

    vector<int> temperatures =
    {73,74,75,71,69,72,76,73};

    Solution obj;

    vector<int> ans =
        obj.dailyTemperatures(
            temperatures);

    for(int x : ans)
        cout << x << " ";

    return 0;
}