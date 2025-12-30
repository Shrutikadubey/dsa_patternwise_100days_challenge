//date-30/12/25
//link-https://leetcode.com/problems/ransom-note/description/
/*Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
Each letter in magazine can only be used once in ransomNote.

Example 1:
Input: ransomNote = "a", magazine = "b"
Output: false*/

//code-
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
      vector<int> freq(26, 0);
        for(char c : magazine) {
            freq[c - 'a']++;
        }
        for(char c : ransomNote) {
            if(freq[c - 'a'] == 0) {
                return false;
            }
            freq[c - 'a']--;
        }
        return true;  
    }
};