//date-21/1/26
//link-https://leetcode.com/problems/flood-fill/description/
/*You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.

 

Example 1:

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2

Output: [[2,2,2],[2,2,0],[2,0,1]]*/
//code-

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
 int rows, cols;
    int originalColor;

    void dfs(int r, int c, vector<vector<int>>& image, int color) {
        // Boundary check
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            return;

        // If color doesn't match original, stop
        if (image[r][c] != originalColor)
            return;

        // Fill the color
        image[r][c] = color;

        // Explore 4 directions
        dfs(r + 1, c, image, color);
        dfs(r - 1, c, image, color);
        dfs(r, c + 1, image, color);
        dfs(r, c - 1, image, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       rows = image.size();
        cols = image[0].size();
        originalColor = image[sr][sc];

        // Edge case: no change needed
        if (originalColor == color)
            return image;

        dfs(sr, sc, image, color);
        return image;  
    }
};