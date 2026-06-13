/*
--------------------------------------------------
Problem: LeetCode 155 - Min Stack
Topic: Stack Design
Day: 11/50
Difficulty: Medium

Time Complexity:
push()   O(1)
pop()    O(1)
top()    O(1)
getMin() O(1)

Space Complexity: O(n)

Author: Nirnay Singh
--------------------------------------------------
*/

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:

    stack<pair<int,int>> st;

public:

    void push(int val) {

        if(st.empty()) {

            st.push({val,val});
        }
        else {

            st.push({
                val,
                min(val,
                    st.top().second)
            });
        }
    }

    void pop() {

        st.pop();
    }

    int top() {

        return st.top().first;
    }

    int getMin() {

        return st.top().second;
    }
};

int main() {

    MinStack st;

    st.push(-2);
    st.push(0);
    st.push(-3);

    cout << "Min: "
         << st.getMin()
         << endl;

    st.pop();

    cout << "Top: "
         << st.top()
         << endl;

    cout << "Min: "
         << st.getMin();

    return 0;
}