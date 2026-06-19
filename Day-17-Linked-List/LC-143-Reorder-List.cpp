/*
--------------------------------------------------
Problem: LeetCode 143 - Reorder List
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
private:

    ListNode* reverse(ListNode* head) {

        ListNode* prev = NULL;

        while(head) {

            ListNode* nextNode =
                head->next;

            head->next = prev;

            prev = head;
            head = nextNode;
        }

        return prev;
    }

public:

    void reorderList(ListNode* head) {

        if(!head || !head->next)
            return;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next &&
              fast->next->next) {

            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second =
            reverse(slow->next);

        slow->next = NULL;

        ListNode* first = head;

        while(second) {

            ListNode* temp1 =
                first->next;

            ListNode* temp2 =
                second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};

void printList(ListNode* head) {

    while(head) {

        cout << head->val << " ";
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

    obj.reorderList(head);

    printList(head);

    return 0;
}