//date-28/11/25
//link-https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters
/*Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.
if no such substring exists, return 0.

Example 1:
Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.*/
//code-
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int ans = 0;

        for (int target = 1; target <= 26; target++) {
            vector<int> freq(26, 0);

            int left = 0, right = 0;
            int unique = 0;      // unique characters in window
            int atLeastK = 0;    // characters which appear >= k times

            while (right < n) {

                // expand window
                if (freq[s[right] - 'a'] == 0)
                    unique++;

                freq[s[right] - 'a']++;

                if (freq[s[right] - 'a'] == k)
                    atLeastK++;

                right++;

                // shrink window if unique > target
                while (unique > target) {
                    if (freq[s[left] - 'a'] == k)
                        atLeastK--;

                    freq[s[left] - 'a']--;

                    if (freq[s[left] - 'a'] == 0)
                        unique--;

                    left++;
                }

                // valid window
                if (unique == target && unique == atLeastK) {
                    ans = max(ans, right - left);
                }
            }
        }

        return ans; 
    }
};