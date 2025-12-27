//date-26/12/25
//link-https://leetcode.com/problems/remove-nodes-from-linked-list/description/
/*You are given the head of a linked list.
Remove every node which has a node with a greater value anywhere to the right side of it.Return the head of the modified linked list.

Example 1:
Input: head = [5,2,13,3,8]
Output: [13,8]
Explanation: The nodes that should be removed are 5, 2 and 3.
- Node 13 is to the right of node 5.
- Node 13 is to the right of node 2.
- Node 8 is to the right of node 3.*/

//code-
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
 ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        head = reverseList(head);

        // Step 2: Remove nodes smaller than max seen so far
        int maxVal = head->val;
        ListNode* curr = head;

        while (curr && curr->next) {
            if (curr->next->val < maxVal) {
                curr->next = curr->next->next; // remove node
            } else {
                curr = curr->next;
                maxVal = curr->val;
            }
        }

        // Step 3: Reverse again
        return reverseList(head);
    }
};