//date-13/12/25
//link-https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion
/*Given an array of integers, return the maximum sum for a non-empty subarray (contiguous elements) with at most one element deletion. In other words, you want to choose a subarray and optionally delete one element from it so that there is still at least one element left and the sum of the remaining elements is maximum possible.
Note that the subarray needs to be non-empty after deleting one element.
Example 1:
Input: arr = [1,-2,0,3]
Output: 4
Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the subarray [1, 0, 3] becomes the maximum value.*/

//code-
#include<bits/c++.h>
using namespace std;
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        left[0] = arr[0];
        int ans = arr[0];
        for (int i = 1; i < n; i++) {
            left[i] = max(arr[i], left[i - 1] + arr[i]);
            ans = max(ans, left[i]);
        }
        right[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(arr[i], right[i + 1] + arr[i]);
        }
        for (int i = 1; i < n - 1; i++) {
            ans = max(ans, left[i - 1] + right[i + 1]);
        }

        return ans;
    }
};