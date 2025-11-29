//date-29/11/25
//link-https://leetcode.com/problems/contains-duplicate-ii
/*Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

Example 1:
Input: nums = [1,2,3,1], k = 3
Output: true*/

//code-
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
         unordered_set<int> window;
         int left = 0;
         for (int right = 0; right < nums.size(); right++) {
            if (window.count(nums[right])) {
                return true;
            }
            window.insert(nums[right]);
                if (right - left >= k) {
                    window.erase(nums[left]);
                    left++;
                }
            }
         return false;
    }
};