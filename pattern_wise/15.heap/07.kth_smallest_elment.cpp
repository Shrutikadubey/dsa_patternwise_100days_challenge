//date-31/1/26
//link-https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix
/*Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n2).

 

Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13*/

//code-
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
      int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];
        // Function to count elements <= mid
        auto countLessEqual = [&](int mid) {
            int count = 0;
            int row = n - 1;
            int col = 0;

            while (row >= 0 && col < n) {
                if (matrix[row][col] <= mid) {
                    count += row + 1;   // all elements above are <= mid
                    col++;
                } else {
                    row--;
                }
            }
            return count;
        };
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (countLessEqual(mid) < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;  
    }
};