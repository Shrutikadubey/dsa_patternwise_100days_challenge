//date-7/12/25
//link-
/*You are playing a game involving a circular array of non-zero integers nums. Each nums[i] denotes the number of indices forward/backward you must move if you are located at index i:
If nums[i] is positive, move nums[i] steps forward, and
If nums[i] is negative, move abs(nums[i]) steps backward.
Since the array is circular, you may assume that moving forward from the last element puts you on the first element, and moving backwards from the first element puts you on the last element.
A cycle in the array consists of a sequence of indices seq of length k where:
Following the movement rules above results in the repeating index sequence seq[0] -> seq[1] -> ... -> seq[k - 1] -> seq[0] -> ...
Every nums[seq[j]] is either all positive or all negative.
k > 1
Return true if there is a cycle in nums, or false otherwise.
Example 1:
Input: nums = [2,-1,1,2,2]
Output: true
Explanation: The graph shows how the indices are connected. White nodes are jumping forward, while red is jumping backward.
We can see the cycle 0 --> 2 --> 3 --> 0 --> ..., and all of its nodes are white (jumping in the same direction).*/

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
    int nextIndex(vector<int>& nums, int i) {
        int n = nums.size();
        return ((i + nums[i]) % n + n) % n; 
    }
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue; 

            bool dir = nums[i] > 0;     
            int slow = i, fast = i;

            while (true) {
                int nextSlow = nextIndex(nums, slow);
                if (nums[nextSlow] == 0 || (nums[nextSlow] > 0) != dir) break;
                int nextFast = nextIndex(nums, fast);
                if (nums[nextFast] == 0 || (nums[nextFast] > 0) != dir) break;
                nextFast = nextIndex(nums, nextFast);
                if (nums[nextFast] == 0 || (nums[nextFast] > 0) != dir) break;

                slow = nextSlow;
                fast = nextFast;

                if (slow == fast) {
                    if (slow == nextIndex(nums, slow)) break;
                    return true;
                }
            }
            int idx = i;
            while (nums[idx] != 0 && (nums[idx] > 0) == dir) {
                int nxt = nextIndex(nums, idx);
                nums[idx] = 0;
                idx = nxt;
            }
        }
        return false;
    }
};