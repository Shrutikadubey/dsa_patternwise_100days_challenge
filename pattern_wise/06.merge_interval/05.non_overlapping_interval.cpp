//date-20/12/25
//link-https://leetcode.com/problems/non-overlapping-intervals/description/
/*Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.

Example 1:
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.*/

//code-
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;
    sort(intervals.begin(), intervals.end(),
         [](vector<int>& a, vector<int>& b) {
             return a[1] < b[1];
         });
    int remove = 0;
    int prevEnd = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] < prevEnd) {
            remove++;
        } else {
            prevEnd = intervals[i][1];
        }
    }
    return remove;
    }
};