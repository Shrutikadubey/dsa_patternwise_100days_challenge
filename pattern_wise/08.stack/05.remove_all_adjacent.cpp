//date-26/12/25
//link-https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/description/
/*You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.
We repeatedly make k duplicate removals on s until we no longer can.
Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.

Example 1:

Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.*/
//code-
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s, int k) {
    stack<pair<char, int>> st;
    for (char c : s) {
        if (!st.empty() && st.top().first == c) {
            st.top().second++;
            if (st.top().second == k) {
                st.pop();
            }
        } else {
            st.push({c, 1});
        }
    }
    string result;
    while (!st.empty()) {
        result.append(st.top().second, st.top().first);
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;  
    }
};