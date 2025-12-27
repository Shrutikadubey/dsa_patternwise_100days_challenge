//date-27/12/25
//link-https://leetcode.com/problems/remove-k-digits/
/*Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

 

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.*/

//code-
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
    string st;  
    for (char c : num) {
        while (!st.empty() && k > 0 && st.back() > c) {
            st.pop_back();
            k--;
        }
        st.push_back(c);
    }
    while (k > 0 && !st.empty()) {
        st.pop_back();
        k--;
    }
    int idx = 0;
    while (idx < st.size() && st[idx] == '0') {
        idx++;
    }
    string result = st.substr(idx);
    return result.empty() ? "0" : result;
    }
};