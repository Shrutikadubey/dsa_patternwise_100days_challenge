//date-7/2/26
//link-https://leetcode.com/problems/maximum-length-of-pair-chain/
/*You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.

A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.

Return the length longest chain which can be formed.

You do not need to use up all the given intervals. You can select pairs in any order.

 

Example 1:

Input: pairs = [[1,2],[2,3],[3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4].*/
//code-
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
       sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });
        int count = 1;
        int lastEnd = pairs[0][1];
        for (int i = 1; i < pairs.size(); i++) {
            if (pairs[i][0] > lastEnd) {
                count++;
                lastEnd = pairs[i][1];
            }
        }

        return count; 
    }
};