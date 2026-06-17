/*
--------------------------------------------------
Problem: LeetCode 141 - Linked List Cycle
Topic: Linked List
Day: 15/50
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

    bool hasCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast &&
              fast->next) {

            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
                return true;
        }

        return false;
    }
};

int main() {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    head->next->next->next = head;

    Solution obj;

    cout << boolalpha
         << obj.hasCycle(head);

    return 0;
}