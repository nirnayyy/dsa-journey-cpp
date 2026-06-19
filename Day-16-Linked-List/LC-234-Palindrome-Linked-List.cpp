/*
--------------------------------------------------
Problem: LeetCode 234
Palindrome Linked List

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

    ListNode* reverse(
        ListNode* head) {

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

    bool isPalindrome(
        ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast &&
              fast->next) {

            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf =
            reverse(slow);

        ListNode* firstHalf =
            head;

        while(secondHalf) {

            if(firstHalf->val !=
               secondHalf->val)

                return false;

            firstHalf =
                firstHalf->next;

            secondHalf =
                secondHalf->next;
        }

        return true;
    }
};

int main() {

    ListNode* head =
        new ListNode(1);

    head->next =
        new ListNode(2);

    head->next->next =
        new ListNode(2);

    head->next->next->next =
        new ListNode(1);

    Solution obj;

    cout << boolalpha
         << obj.isPalindrome(head);

    return 0;
}