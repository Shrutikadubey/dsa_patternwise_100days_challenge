//date-14/12/25
//link-https://leetcode.com/problems/count-of-range-sum
/*Given an integer array nums and two integers lower and upper, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j inclusive, where i <= j.
Example 1:
Input: nums = [-2,5,-1], lower = -2, upper = 2
Output: 3
Explanation: The three ranges are: [0,0], [2,2], and [0,2] and their respective sums are: -2, -1, 2.*/
//code-
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        return mergeSort(prefix, 0, n, lower, upper);
    }

private:
    int mergeSort(vector<long long>& prefix, int left, int right,
         int lower, int upper) {
        if (left >= right) return 0;
        int mid = left + (right - left) / 2;
        int count = 0;
        count += mergeSort(prefix, left, mid, lower, upper);
        count += mergeSort(prefix, mid + 1, right, lower, upper);
        int j = mid + 1, k = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && prefix[j] - prefix[i] < lower) j++;
            while (k <= right && prefix[k] - prefix[i] <= upper) k++;
            count += (k - j);
        }
        vector<long long> temp;
        int p1 = left, p2 = mid + 1;
        while (p1 <= mid && p2 <= right) {
            if (prefix[p1] <= prefix[p2])
                temp.push_back(prefix[p1++]);
            else
                temp.push_back(prefix[p2++]);
        }
        while (p1 <= mid) temp.push_back(prefix[p1++]);
        while (p2 <= right) temp.push_back(prefix[p2++]);
        for (int i = left; i <= right; i++) {
            prefix[i] = temp[i - left];
        }
        return count;
    }
};