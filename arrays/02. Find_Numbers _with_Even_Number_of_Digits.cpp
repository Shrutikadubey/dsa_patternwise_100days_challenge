//date-10/11/25
//link-https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
/*Given an array nums of integers, return how many of them contain an even number of digits.

 

Example 1:

Input: nums = [12,345,2,6,7896]
Output: 2
Explanation: 
12 contains 2 digits (even number of digits). 
345 contains 3 digits (odd number of digits). 
2 contains 1 digit (odd number of digits). 
6 contains 1 digit (odd number of digits). 
7896 contains 4 digits (even number of digits). 
Therefore only 12 and 7896 contain an even number of digits.*/

//code-
#include <vector>
using namespace std;
class Solution {
public:
    int countDigits(int num) {
    int digits = 0;
    while (num > 0) {
        digits++;
        num /= 10;
    }
    return digits;
} 
    int findNumbers(vector<int>& nums) {
         int count = 0;
        for (int num : nums) {
        int digits = countDigits(num);
        if (digits % 2 == 0) count++;
        }
     return count;
    }
};