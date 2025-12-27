//date-27/12/25
//link-https://neetcode.io/problems/product-of-array-except-self/question
/*Given an integer array nums, return an array output where output[i] is the product of all the elements of nums except nums[i].
Each product is guaranteed to fit in a 32-bit integer.

Example 1:
Input: nums = [1,2,4,6]
Output: [48,24,12,8]*/

//code-
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
    vector<int> output(n, 1);
    int prefix = 1;
    for (int i = 0; i < n; i++) {
        output[i] = prefix;
        prefix *= nums[i];
    }
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        output[i] *= suffix;
        suffix *= nums[i];
    }

    return output;
    }
};
