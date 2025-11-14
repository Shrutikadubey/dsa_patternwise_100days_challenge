//date-10/11/25
//link-https://leetcode.com/problems/max-consecutive-ones/
/*Given a binary array nums, return the maximum number of consecutive 1's in the array.

 

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.*/

//code-
#include <vector>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, maxCount = 0;
        for (int num : nums) {
            if (num == 1) {
                count++;
                maxCount = max(maxCount, count);
            } else {
                count = 0; // reset when 0 found
            }
        }
        return maxCount;
    }
};