/*
--------------------------------------------------
Problem: LeetCode 84 - Largest Rectangle in Histogram
Topic: Monotonic Stack
Day: 12/50
Difficulty: Hard

Time Complexity: O(n)
Space Complexity: O(n)

Author: Nirnay Singh
--------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int> st;

        int n = heights.size();
        int maxArea = 0;

        for(int i = 0; i <= n; i++) {

            int currentHeight =
                (i == n) ? 0 : heights[i];

            while(!st.empty() &&
                  currentHeight <
                  heights[st.top()]) {

                int height =
                    heights[st.top()];

                st.pop();

                int width;

                if(st.empty())
                    width = i;
                else
                    width =
                    i - st.top() - 1;

                maxArea =
                    max(maxArea,
                        height * width);
            }

            st.push(i);
        }

        return maxArea;
    }
};

int main() {

    vector<int> heights =
    {2,1,5,6,2,3};

    Solution obj;

    cout <<
    obj.largestRectangleArea(
        heights);

    return 0;
}