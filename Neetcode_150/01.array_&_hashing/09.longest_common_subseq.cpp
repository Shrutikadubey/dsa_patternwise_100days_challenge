//date-30/12/25
//link-https://neetcode.io/problems/longest-consecutive-sequence/question?list=neetcode150
/*Given an array of integers nums, return the length of the longest consecutive sequence of elements that can be formed.
A consecutive sequence is a sequence of elements in which each element is exactly 1 greater than the previous element. The elements do not have to be consecutive in the original array.
You must write an algorithm that runs in O(n) time.
Example 1:
Input: nums = [2,20,4,10,3,4,5]
Output: 4*/

//code-
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    unordered_set<int> st(nums.begin(), nums.end());
    int longest = 0;
    for (int num : st) {
        if (!st.count(num - 1)) {
            int current = num;
            int length = 1;
            while (st.count(current + 1)) {
                current++;
                length++;
            }
            longest = max(longest, length);
        }
    }
    return longest;  
    }
};
