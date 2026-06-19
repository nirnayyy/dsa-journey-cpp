/*
--------------------------------------------------
Problem: LeetCode 876
Middle of the Linked List

Topic: Linked List
Day: 16/50
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

    ListNode* middleNode(
        ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast &&
              fast->next) {

            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

int main() {

    ListNode* head =
        new ListNode(1);

    head->next =
        new ListNode(2);

    head->next->next =
        new ListNode(3);

    head->next->next->next =
        new ListNode(4);

    head->next->next->next->next =
        new ListNode(5);

    Solution obj;

    cout <<
    obj.middleNode(head)->val;

    return 0;
}