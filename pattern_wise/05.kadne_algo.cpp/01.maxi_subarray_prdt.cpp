//date-12/12/25
//link-https://leetcode.com/problems/maximum-product-subarray
/*Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

Note that the product of an array with a single element is the value of that element.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.*/

//code-
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
      int maxProd = nums[0]; 
        int minProd = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];
            if (curr < 0) {
                swap(maxProd, minProd);
            }
            maxProd = max(curr, maxProd * curr);
            minProd = min(curr, minProd * curr);
            ans = max(ans, maxProd);
        }
        return ans;
    }
};