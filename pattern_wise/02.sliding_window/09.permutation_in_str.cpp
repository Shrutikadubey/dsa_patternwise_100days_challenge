//date-15/12/25
//link-https://leetcode.com/problems/permutation-in-string/
/*Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.
Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").*/

//code-
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n > m) return false;

        vector<int> freq1(26, 0), freq2(26, 0);
        for (char c : s1)
            freq1[c - 'a']++;
        int left = 0;
        for (int right = 0; right < m; right++) {
            freq2[s2[right] - 'a']++;
            if (right - left + 1 > n) {
                freq2[s2[left] - 'a']--;
                left++;
            }
            if (freq1 == freq2)
                return true;
        }

        return false; 
    }
};