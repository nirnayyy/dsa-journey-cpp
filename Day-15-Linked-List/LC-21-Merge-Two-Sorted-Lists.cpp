/*
--------------------------------------------------
Problem: LeetCode 21 - Merge Two Sorted Lists
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

    ListNode* mergeTwoLists(
        ListNode* list1,
        ListNode* list2) {

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(list1 && list2) {

            if(list1->val <= list2->val) {

                tail->next = list1;
                list1 = list1->next;
            }
            else {

                tail->next = list2;
                list2 = list2->next;
            }

            tail = tail->next;
        }

        if(list1)
            tail->next = list1;

        if(list2)
            tail->next = list2;

        return dummy.next;
    }
};

void printList(ListNode* head) {

    while(head) {

        cout << head->val << " ";
        head = head->next;
    }
}

int main() {

    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    Solution obj;

    ListNode* merged =
        obj.mergeTwoLists(list1, list2);

    printList(merged);

    return 0;
}