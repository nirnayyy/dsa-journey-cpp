/*
--------------------------------------------------
Problem: LeetCode 206 - Reverse Linked List
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

    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr) {

            ListNode* nextNode = curr->next;

            curr->next = prev;

            prev = curr;
            curr = nextNode;
        }

        return prev;
    }
};

void printList(ListNode* head) {

    while(head) {

        cout << head->val << " ";
        head = head->next;
    }
}

int main() {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    Solution obj;

    head = obj.reverseList(head);

    printList(head);

    return 0;
}