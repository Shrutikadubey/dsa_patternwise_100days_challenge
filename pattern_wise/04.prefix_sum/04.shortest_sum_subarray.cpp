//date-14/12/25
//link-https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k
/*Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.
A subarray is a contiguous part of an array.
Example 1:
Input: nums = [1], k = 1
Output: 1*/
//code-
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        deque<int> dq;
        int ans = n + 1;
        for (int i = 0; i <= n; i++) {
             while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && prefix[i] <= prefix[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return ans == n + 1 ? -1 : ans; 
    }
};