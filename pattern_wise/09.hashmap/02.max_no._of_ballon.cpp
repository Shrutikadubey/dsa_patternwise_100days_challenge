//date-28/12/25
//link-https://leetcode.com/problems/maximum-number-of-balloons/description/
/*Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.
You can use each character in text at most once. Return the maximum number of instances that can be formed.

Example 1:
Input: text = "nlaebolko"
Output: 1*/

//code-
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxNumberOfBalloons(string text) {
    unordered_map<char, int> freq;
    for (char c : text) {
        freq[c]++;
    }
    return min({
        freq['b'],
        freq['a'],
        freq['l'] / 2,
        freq['o'] / 2,
        freq['n']
    });  
    }
};