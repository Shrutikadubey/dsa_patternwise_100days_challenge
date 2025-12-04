//date-03/12/25
//link-https://leetcode.com/problems/split-linked-list-in-parts
/*Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.
The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.
The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.
Return an array of the k parts. 
Example 1:
Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].*/

//code-
#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
         vector<ListNode*> result(k, NULL);
        int n = 0;
        ListNode* curr = head;
        while(curr) {
            n++;
            curr = curr->next;
        }
        int base = n / k;    
        int extra = n % k;     
        curr = head;
        for(int i = 0; i < k && curr != NULL; i++) {            
            result[i] = curr;
            int partSize = base + (extra > 0 ? 1 : 0);
            extra--;        
            for(int j = 1; j < partSize; j++) {
                curr = curr->next;
            }     
            ListNode* nextPart = curr->next;
            curr->next = NULL;
            curr = nextPart;
        }
        return result;
    }
};