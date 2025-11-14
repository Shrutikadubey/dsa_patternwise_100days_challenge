//date-11/11/25
//link-https://leetcode.com/problems/valid-mountain-array/
/*An array arr is a mountain array if the following properties hold:
arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

 

Example 1:

Input: arr = [2,1]
Output: false*/

//code-
#include <vector>
using namespace std;
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
    int n = arr.size();
    if (n < 3) return false; 
    int i = 0;
    while (i + 1 < n && arr[i] < arr[i + 1]) i++;
    if (i == 0 || i == n - 1) return false;
    while (i + 1 < n && arr[i] > arr[i + 1]) i++;
    return i == n - 1;  
    }
};
