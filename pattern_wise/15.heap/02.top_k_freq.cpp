//date-25/1/26
//link-https://leetcode.com/problems/top-k-frequent-words/description/
/*Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

 

Example 1:

Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.*/

//cod-
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
          unordered_map<string, int> freq;
        // Step 1: Count frequencies
        for (auto &word : words) {
            freq[word]++;
        }
        // Step 2: Min heap with custom comparator
        auto cmp = [&](const pair<string,int>& a, const pair<string,int>& b) {
            if (a.second == b.second)
                return a.first < b.first;   // reverse lex order
            return a.second > b.second;     // min heap by frequency
        };

        priority_queue<pair<string,int>, vector<pair<string,int>>, decltype(cmp)> pq(cmp);
        // Step 3: Keep heap size <= k
        for (auto &it : freq) {
            pq.push(it);
            if (pq.size() > k)
                pq.pop();
        }
        // Step 4: Extract result
        vector<string> result;
        while (!pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};