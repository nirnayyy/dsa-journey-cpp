/*
--------------------------------------------------
Problem: LeetCode 19
Remove Nth Node From End

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

    ListNode* removeNthFromEnd(
        ListNode* head,
        int n) {

        ListNode dummy(0);
        dummy.next = head;

        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        for(int i = 0;
            i <= n;
            i++) {

            fast = fast->next;
        }

        while(fast) {

            fast = fast->next;
            slow = slow->next;
        }

        slow->next =
            slow->next->next;

        return dummy.next;
    }
};

void printList(
    ListNode* head) {

    while(head) {

        cout <<
        head->val << " ";

        head = head->next;
    }
}

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

    head =
    obj.removeNthFromEnd(
        head,
        2);

    printList(head);

    return 0;
}