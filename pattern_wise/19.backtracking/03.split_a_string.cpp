//date-15/2/26
//link-https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description/
/*Given a string s, return the maximum number of unique substrings that the given string can be split into.

You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms the original string. However, you must split the substrings such that all of them are unique.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "ababccc"
Output: 5
Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have 'a' and 'b' multiple times.*/

//code-
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxUniqueSplit(string s) {
       unordered_set<string> used;
        return backtrack(s, 0, used);
    }
    
    int backtrack(string &s, int start, unordered_set<string> &used) {
        if (start == s.length()) {
            return 0;
        }
        int maxCount = 0;
        string curr = "";
        for (int i = start; i < s.length(); i++) {
            curr += s[i];
            if (used.find(curr) == used.end()) {
                used.insert(curr);
                maxCount = max(maxCount, 1 + backtrack(s, i + 1, used));
                used.erase(curr);
            }
        }
        return maxCount; 
    }
};