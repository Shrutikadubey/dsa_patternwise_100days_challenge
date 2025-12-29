//date-29/12/25
//link-https://leetcode.com/problems/longest-palindrome/description/
/*Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
Letters are case sensitive, for example, "Aa" is not considered a palindrome.

Example 1:
Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.*/

//code-
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    int length = 0;
    bool hasOdd = false;
    for (auto &p : freq) {
        if (p.second % 2 == 0) {
            length += p.second;
        } else {
            length += p.second - 1;
            hasOdd = true;
        }
    }
    if (hasOdd) length += 1;
    return length; 
    }
};