//date-10/01/26
//link-http://leetcode.com/problems/split-array-largest-sum/description/
/*Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.*/
//code-
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool canSplit(vector<int>& nums, int k, long long maxSum) {
        long long currentSum = 0;
        int subarrays = 1;

        for (int num : nums) {
            if (currentSum + num > maxSum) {
                subarrays++;
                currentSum = num;
            } else {
                currentSum += num;
            }
        }
        return subarrays <= k;
    }

    int splitArray(vector<int>& nums, int k) {
       long long low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (canSplit(nums, k, mid)) {
                high = mid;      // try smaller maximum sum
            } else {
                low = mid + 1;   // need bigger sum
            }
        }
        return low; 
    }
};