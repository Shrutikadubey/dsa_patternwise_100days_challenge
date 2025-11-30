//date-30/11/25
//link-https://leetcode.com/problems/minimum-window-substring
/*Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.*/

//code-
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
         if (t.length() > s.length()) return "";
        unordered_map<char, int> need, window;
        for (char c : t) {
            need[c]++;
        }
        int left = 0, right = 0;
        int required = need.size();   
        int formed = 0;
        int minLen = INT_MAX;
        int start = 0;
        while (right < s.length()) {
            char c = s[right];
            window[c]++;
            if (need.count(c) && window[c] == need[c]) {
                formed++;
            }
            while (left <= right && formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                char removeChar = s[left];
                window[removeChar]--;
                if (need.count(removeChar) && window[removeChar] < need[removeChar]) {
                    formed--;
                }
                left++;
            }
            right++;
        }
        if (minLen == INT_MAX) return "";
        return s.substr(start, minLen);
    }
};