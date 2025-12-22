//date-22/12/25
//link-https://neetcode.io/problems/duplicate-integer/history

/*Given an integer array nums, return true if any value appears more than once in the array, otherwise return false.

Example 1:
Input: nums = [1, 2, 3, 3]
Output: true*/

//code-
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1])
                return true;
        }
        return false;
    }
};