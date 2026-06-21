/*
--------------------------------------------------
Problem: LeetCode 784
Letter Case Permutation

Topic: Recursion
Day: 19/50
--------------------------------------------------
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    vector<string> ans;

    void solve(
        string s,
        int index) {

        if(index == s.size()) {

            ans.push_back(s);
            return;
        }

        if(isalpha(s[index])) {

            s[index] =
                tolower(s[index]);

            solve(s, index + 1);

            s[index] =
                toupper(s[index]);

            solve(s, index + 1);
        }
        else {

            solve(s, index + 1);
        }
    }

    vector<string> letterCasePermutation(
        string s) {

        solve(s, 0);

        return ans;
    }
};

int main() {

    Solution obj;

    vector<string> ans =
        obj.letterCasePermutation("a1b");

    for(string s : ans)
        cout << s << endl;

    return 0;
}