//date-15/12/2025
//link-https://leetcode.com/problems/minimum-window-substring/
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
       if (t.size() > s.size()) return "";
        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;
        int required = need.size();
        int formed = 0;
        int l = 0, r = 0;
        int minLen = INT_MAX, start = 0;
        while (r < s.size()) {
            char c = s[r];
            window[c]++;
            if (need.count(c) && window[c] == need[c])
                formed++;
            while (l <= r && formed == required) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }
                char leftChar = s[l];
                window[leftChar]--;

                if (need.count(leftChar) && window[leftChar] < need[leftChar])
                    formed--;

                l++;
            }
            r++;
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);  
    }
};