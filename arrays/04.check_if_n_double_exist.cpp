//date-11/11/25
//link-https://leetcode.com/problems/check-if-n-and-its-double-exist
/*Given an array arr of integers, check if there exist two indices i and j such that :

i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]
 

Example 1:

Input: arr = [10,2,5,3]
Output: true
Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]*/

//code-
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
    unordered_set<int> seen;
    
    for (int num : arr) {
        if (seen.count(2 * num) || (num % 2 == 0 && seen.count(num / 2))) {
            return true;
        }
        seen.insert(num);
    }
    return false;
    }
};