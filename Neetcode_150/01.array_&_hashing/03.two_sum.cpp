//date-23/12/25
//link-https://neetcode.io/problems/two-sum/question?list=neetcode150
/*Given an array of integers nums and an integer target, return the indices i and j such that nums[i] + nums[j] == target and i != j.
You may assume that every input has exactly one pair of indices i and j that satisfy the condition.
Return the answer with the smaller index first.
Example 1:
Input: 
nums = [3,4,5,6], target = 7
Output: [0,1]*/

//code-
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         unordered_map<int, int> mp; // value -> index
        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];
            if (mp.find(need) != mp.end()) {
                return {mp[need], i}; 
            }
            mp[nums[i]] = i;
        }
        return {}; 
    }
};


// intution using hashmap
// ""We store previous elements in a map
// For each nums[i], check if target - nums[i] exists
// If yes → return indices
// If not → store current value""