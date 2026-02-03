//date-3/2/26
//link-https://leetcode.com/problems/reorganize-string/description/
/*Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
Return any possible rearrangement of s or return "" if not possible.

Example 1:
Input: s = "aab"
Output: "aba"*/
//code-
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0)
                pq.push({freq[i], char('a' + i)});
        }
        if (pq.top().first > (s.length() + 1) / 2)
            return "";
        string result = "";
        while (pq.size() >= 2) {
            auto [f1, c1] = pq.top(); pq.pop();
            auto [f2, c2] = pq.top(); pq.pop();
            result += c1;
            result += c2;
            if (--f1 > 0) pq.push({f1, c1});
            if (--f2 > 0) pq.push({f2, c2});
        }
        if (!pq.empty()) {
            result += pq.top().second;
        }
        return result;
    }
};