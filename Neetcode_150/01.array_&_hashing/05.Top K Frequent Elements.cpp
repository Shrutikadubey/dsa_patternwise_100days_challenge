//date-25/12/25
//link-https://neetcode.io/problems/top-k-elements-in-list/question
/*Given an integer array nums and an integer k, return the k most frequent elements within the array.

The test cases are generated such that the answer is always unique.

You may return the output in any order.

Example 1:

Input: nums = [1,2,2,3,3,3], k = 2

Output: [2,3]*/
//code-
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto &it : freq) {
        pq.push({it.second, it.first});
        if (pq.size() > k) {
            pq.pop();
        }
    }
    vector<int> result;
    while (!pq.empty()) {
        result.push_back(pq.top().second);
        pq.pop();
    }
    return result;  
    }
};
