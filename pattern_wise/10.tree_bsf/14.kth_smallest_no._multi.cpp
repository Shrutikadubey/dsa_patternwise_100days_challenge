//date-14/01/26
//link-https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/description/
/*Nearly everyone has used the Multiplication Table. The multiplication table of size m x n is an integer matrix mat where mat[i][j] == i * j (1-indexed).

Given three integers m, n, and k, return the kth smallest element in the m x n multiplication table.


Example 1:
Input: m = 3, n = 3, k = 5
Output: 3
Explanation: The 5th smallest number is 3.*/
//code-
#include <algorithm>
using namespace std;
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int low = 1, high = m * n;
    while (low < high) {
        int mid = low + (high - low) / 2;
        long long count = 0;
        for (int i = 1; i <= m; i++) {
            count += min(n, mid / i);
        }
        if (count >= k)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
    }
};