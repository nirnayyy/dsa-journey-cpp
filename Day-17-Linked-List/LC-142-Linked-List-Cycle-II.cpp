/*
--------------------------------------------------
Problem: LeetCode 142 - Linked List Cycle II
Topic: Linked List
Day: 17/50
Difficulty: Medium

Time Complexity: O(n)
Space Complexity: O(1)

Author: Nirnay Singh
--------------------------------------------------
*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:

    ListNode* detectCycle(
        ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast &&
              fast->next) {

            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {

                ListNode* entry =
                    head;

                while(entry != slow) {

                    entry =
                        entry->next;

                    slow =
                        slow->next;
                }

                return entry;
            }
        }

        return NULL;
    }
};

int main() {

    ListNode* head =
        new ListNode(3);

    ListNode* node2 =
        new ListNode(2);

    ListNode* node0 =
        new ListNode(0);

    ListNode* node4 =
        new ListNode(-4);

    head->next = node2;
    node2->next = node0;
    node0->next = node4;

    node4->next = node2;

    Solution obj;

    ListNode* ans =
        obj.detectCycle(head);

    if(ans)
        cout << ans->val;
    else
        cout << "No Cycle";

    return 0;
}