//date-8/12/25
//link-https://leetcode.com/problems/subarray-sum-equals-k
/*Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.
Example 1:
Input: nums = [1,1,1], k = 2
Output: 2*/
//code-
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1; 
        
        int prefixSum = 0;
        int count = 0;
        
        for(int num : nums) {
            prefixSum += num;
            if(mp.find(prefixSum - k) != mp.end()) {
                count += mp[prefixSum - k];
            }
            mp[prefixSum]++;
        }
        
        return count;
    }
};