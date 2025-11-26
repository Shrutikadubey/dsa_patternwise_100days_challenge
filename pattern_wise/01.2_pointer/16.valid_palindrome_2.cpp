//dat1-20/11/25

// day14
//link-https://leetcode.com/problems/valid-palindrome-ii/
/*Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

Example 1:

Input: s = "aba"
Output: true*/
//code-
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool validPalindrome(string s) {
           int l = 0, r = s.size() - 1;

        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            } else {
                // Try deleting left character or right character
                return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
            }
        }
        return true;
    }

    bool isPalindrome(const string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};