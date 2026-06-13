/*
--------------------------------------------------
Problem: LeetCode 20 - Valid Parentheses
Topic: Stack
Day: 11/50
Difficulty: Easy

Time Complexity: O(n)
Space Complexity: O(n)

Author: Nirnay Singh
--------------------------------------------------
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for(char ch : s) {

            if(ch == '(' ||
               ch == '[' ||
               ch == '{') {

                st.push(ch);
            }

            else {

                if(st.empty())
                    return false;

                if(ch == ')' &&
                   st.top() != '(')
                    return false;

                if(ch == ']' &&
                   st.top() != '[')
                    return false;

                if(ch == '}' &&
                   st.top() != '{')
                    return false;

                st.pop();
            }
        }

        return st.empty();
    }
};

int main() {

    string s = "()[]{}";

    Solution obj;

    cout << boolalpha
         << obj.isValid(s);

    return 0;
}