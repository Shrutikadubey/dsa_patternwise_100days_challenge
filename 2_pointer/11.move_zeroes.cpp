//date-12/11/25
//link-https://leetcode.com/problems/move-zeroes
/*Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]*/
//code-
#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
         int j = 0; // pointer to place next non-zero element
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};

