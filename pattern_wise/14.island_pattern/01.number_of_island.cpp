//date-20/1/26
//link-https://leetcode.com/problems/number-of-islands/description/
/*Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1*/

//code-
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int m = grid.size(), n = grid[0].size();
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == '0')
            return;

        grid[r][c] = '0'; // mark visited

        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};