//date-13/12/25
//link-https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray
/*You are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).

Return the maximum absolute sum of any (possibly empty) subarray of nums.

Note that abs(x) is defined as follows:

If x is a negative integer, then abs(x) = -x.
If x is a non-negative integer, then abs(x) = x.
 

Example 1:

Input: nums = [1,-3,2,3,-4]
Output: 5
Explanation: The subarray [2,3] has absolute sum = abs(2+3) = abs(5) = 5.*/

//code-
#include<bits/c++.h>
using namespace std;
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0;   
        int minSum = 0;   
        int currMax = 0;
        int currMin = 0;
        for (int x : nums) {
            currMax = max(x, currMax + x);
            maxSum = max(maxSum, currMax);
            currMin = min(x, currMin + x);
            minSum = min(minSum, currMin);
        }
        return max(maxSum, abs(minSum)); 
    }
};
