//date-14/11/25
//link-https://leetcode.com/problems/3sum-closest/
/*Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).*/

//code-
#include <bits/stdc++.h>
using namespace std;
int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());  // Step 1: Sort array

    int n = nums.size();
    int closestSum = nums[0] + nums[1] + nums[2]; // Initially first three ka sum

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int curr = nums[i] + nums[left] + nums[right];

            // Agar current sum target ke zyada close ho → update
            if (abs(curr - target) < abs(closestSum - target)) {
                closestSum = curr;
            }

            // Pointer movement logic
            if (curr < target) {
                left++;  // Sum chhota hai → badhane ke liye left++
            } else if (curr > target) {
                right--; // Sum bada hai → kam karne ke liye right--
            } else {
                return curr;  // Perfect match mil gaya
            }
        }
    }

    return closestSum;
}
