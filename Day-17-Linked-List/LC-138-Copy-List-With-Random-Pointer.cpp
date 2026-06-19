/*
--------------------------------------------------
Problem: LeetCode 138
Copy List With Random Pointer

Topic: Linked List + Hash Map
Day: 17/50
Difficulty: Medium

Time Complexity: O(n)
Space Complexity: O(n)

Author: Nirnay Singh
--------------------------------------------------
*/

#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:

    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:

    Node* copyRandomList(
        Node* head) {

        unordered_map<Node*, Node*> mp;

        Node* curr = head;

        while(curr) {

            mp[curr] =
                new Node(curr->val);

            curr = curr->next;
        }

        curr = head;

        while(curr) {

            mp[curr]->next =
                mp[curr->next];

            mp[curr]->random =
                mp[curr->random];

            curr = curr->next;
        }

        return mp[head];
    }
};

int main() {

    Node* head =
        new Node(7);

    Node* node2 =
        new Node(13);

    Node* node3 =
        new Node(11);

    head->next = node2;
    node2->next = node3;

    node2->random = head;

    Solution obj;

    Node* copy =
        obj.copyRandomList(head);

    cout << "Copied Head Value: "
         << copy->val;

    return 0;
}