/*
--------------------------------------------------
Problem: LeetCode 142 - Linked List Cycle II
Topic: Fast & Slow Pointer
Day: 8/50
Difficulty: Medium

Time Complexity: O(n)
Space Complexity: O(1)

Author: Nirnay Singh
--------------------------------------------------
*/

#include <iostream>

using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {

            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {

                ListNode* ptr = head;

                while(ptr != slow) {

                    ptr = ptr->next;
                    slow = slow->next;
                }

                return ptr;
            }
        }

        return nullptr;
    }
};

int main() {

    ListNode* n1 = new ListNode(3);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(0);
    ListNode* n4 = new ListNode(-4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    // Creating cycle
    n4->next = n2;

    Solution obj;

    ListNode* ans =
        obj.detectCycle(n1);

    if(ans)
        cout << "Cycle starts at node: "
             << ans->val;
    else
        cout << "No cycle";

    return 0;
}