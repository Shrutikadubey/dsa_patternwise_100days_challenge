//date-26/1/26
//link-https://leetcode.com/problems/k-closest-points-to-origin/description/
/*Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).
The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).
You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
Example 1:
Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]*/
//code-
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [](auto &a, auto &b) {
        int da = a[0]*a[0] + a[1]*a[1];
        int db = b[0]*b[0] + b[1]*b[1];
        return da < db;
    });

    return vector<vector<int>>(points.begin(), points.begin() + k); 
    }
};