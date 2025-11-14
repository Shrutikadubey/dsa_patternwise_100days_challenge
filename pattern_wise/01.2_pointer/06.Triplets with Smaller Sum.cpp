//date-09/11/25
//link-https://www.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1
/*Given an array arr[] of distinct integers of size n and a value sum, the task is to find the count of triplets (i, j, k), having (i<j<k) with the sum of (arr[i] + arr[j] + arr[k]) smaller than the given value sum.


Examples :


Input: n = 4, sum = 2, arr[] = {-2, 0, 1, 3}
Output:  2
Explanation: Below are triplets with sum less than 2 (-2, 0, 1) and (-2, 0, 3). */

//code-
#include <vector>
#include <algorithm>   
using namespace std;
class Solution {

  public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        // Your code goes here
        sort(arr, arr + n);
        int count = 0;

        for (int i = 0; i < n - 2; i++) {
        int left = i + 1, right = n - 1;
        while (left < right) {
            int current_sum = arr[i] + arr[left] + arr[right];
            if (current_sum < sum) {
                // All triplets from (left, left+1, ..., right) with arr[i] are valid
                count += (right - left);
                left++;
            } else {
                right--;
               }
            }
         }
        return count;

    }
};