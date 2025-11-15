//date-15/11/25
//link-https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k
/*You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

The length of the subarray is k, and
All the elements of the subarray are distinct.
Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,5,4,2,9,9,9], k = 3
Output: 15
Explanation: The subarrays of nums with length 3 are:
- [1,5,4] which meets the requirements and has a sum of 10.
- [5,4,2] which meets the requirements and has a sum of 11.
- [4,2,9] which meets the requirements and has a sum of 15.
- [2,9,9] which does not meet the requirements because the element 9 is repeated.
- [9,9,9] which does not meet the requirements because the element 9 is repeated.
We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions*/

//code-
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        long long currSum = 0, maxSum = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;
            currSum += nums[right];

            // Window reached size k
            if (right - left + 1 == k) {

                // Check if window has all distinct elements
                if (freq.size() == k) {
                    maxSum = max(maxSum, currSum);
                }

                // Slide window: remove left element
                freq[nums[left]]--;
                currSum -= nums[left];

                if (freq[nums[left]] == 0)
                    freq.erase(nums[left]);

                left++;
            }
        }

        return maxSum;
    }
};