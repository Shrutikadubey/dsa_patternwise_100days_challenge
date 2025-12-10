//date-10/12/25
//link-https://leetcode.com/problems/contiguous-array
/*Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
 
Example 1:
Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.*/
//code-
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;  
        mp[0] = -1;  
        
        int prefix = 0;
        int maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefix += (nums[i] == 0 ? -1 : 1);

            if (mp.count(prefix)) {
                maxLen = max(maxLen, i - mp[prefix]);
            } else {
                mp[prefix] = i; 
            }
        }

        return maxLen;
    }
};