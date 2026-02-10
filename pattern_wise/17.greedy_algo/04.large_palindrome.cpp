//date-10/2/26
//link-https://leetcode.com/problems/largest-palindromic-number/
/*You are given a string num consisting of digits only.

Return the largest palindromic integer (in the form of a string) that can be formed using digits taken from num. It should not contain leading zeroes.

Notes:

You do not need to use all the digits of num, but you must use at least one digit.
The digits can be reordered.
 

Example 1:

Input: num = "444947137"
Output: "7449447"
Explanation: 
Use the digits "4449477" from "444947137" to form the palindromic integer "7449447".
It can be shown that "7449447" is the largest palindromic integer that can be formed.*/
//code-
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string largestPalindromic(string num) {
       vector<int> cnt(10, 0);
        for (char c : num) cnt[c - '0']++;

        string left = "";
        for (int d = 9; d >= 0; d--) {
            while (cnt[d] >= 2) {
                // Avoid leading zero
                if (left.empty() && d == 0) break;
                left.push_back(d + '0');
                cnt[d] -= 2;
            }
        }
        char mid = '\0';
        for (int d = 9; d >= 0; d--) {
            if (cnt[d] > 0) {
                mid = d + '0';
                break;
            }
        }
        string right = left;
        reverse(right.begin(), right.end());

        if (left.empty() && mid == '\0')
            return "0";

        return mid == '\0' ? left + right : left + mid + right;  
    }
};