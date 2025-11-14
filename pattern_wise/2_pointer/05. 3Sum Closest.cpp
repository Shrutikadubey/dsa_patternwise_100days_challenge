//date-09/11/25
//link-https://leetcode.com/problems/3sum-closest/
/*Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.
Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).*/

//code-
#include <vector>
#include <algorithm>   
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
         sort(nums.begin(), nums.end());  // Sort the array
        int closestSum = nums[0] + nums[1] + nums[2];  // Initialize with the first 3 elements

        for (int i = 0; i < nums.size() - 2; ++i) {
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int currSum = nums[i] + nums[left] + nums[right];

                // Update closest sum if this one is closer
                if (abs(currSum - target) < abs(closestSum - target)) {
                    closestSum = currSum;
                }

                // Move pointers
                if (currSum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return closestSum;
    }
};