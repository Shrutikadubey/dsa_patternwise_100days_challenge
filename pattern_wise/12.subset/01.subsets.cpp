//date-19/1/26
//link-https://leetcode.com/problems/subsets/description/
/*Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]*/
//code-
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
     vector<vector<int>> result;

    void backtrack(int index, vector<int>& nums, vector<int>& current) {
        result.push_back(current);

        for (int i = index; i < nums.size(); i++) {
            current.push_back(nums[i]);
            backtrack(i + 1, nums, current);
            current.pop_back(); // backtrack
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        backtrack(0, nums, current);
        return result; 
    }
};