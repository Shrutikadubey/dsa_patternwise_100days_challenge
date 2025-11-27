//date-27/11/25
//link-https://leetcode.com/problems/reverse-words-in-a-string
/*Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
Return a string of the words in reverse order concatenated by a single space.
Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

Example 1:
Input: s = "the sky is blue"
Output: "blue is sky the"*/

//code
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
         vector<string> words;
        string word = "";

        // Step 1: Extract words
        for (char ch : s) {
            if (ch == ' ') {
                if (!word.empty()) {
                    words.push_back(word);
                    word = "";
                }
            } else {
                word += ch;
            }
        }
        // Add last word if exists
        if (!word.empty()) {
            words.push_back(word);
        }

        // Step 2: Build result in reverse order
        string result = "";
        for (int i = words.size() - 1; i >= 0; i--) {
            result += words[i];
            if (i != 0) {
                result += " ";
            }
        }

        return result;
    }
};