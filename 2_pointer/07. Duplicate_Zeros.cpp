//date-10/11/25
//link-https://leetcode.com/problems/duplicate-zeros/
/*Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.

 

Example 1:

Input: arr = [1,0,2,3,0,4,5,0]
Output: [1,0,0,2,3,0,0,4]
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]*/

//code-
#include <vector>
using namespace std;
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
    int zeros = 0;

    // Count how many zeros can be duplicated within the array bounds
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) zeros++;
    }

    int i = n - 1;
    int j = n + zeros - 1; // virtual extended index (after duplicating zeros)

    // Traverse backwards
    while (i >= 0 && j >= 0) {
        if (j < n)
            arr[j] = arr[i]; // move element to new position

        if (arr[i] == 0) {
            j--;
            if (j < n)
                arr[j] = 0; // duplicate the zero
        }
        i--;
        j--;
    }
    }
};