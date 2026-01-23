//date-22/1/26
//link-https://leetcode.com/problems/number-of-closed-islands/description/
/*Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.

 

Example 1:



Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).*/
//code-
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
 int m, n;

    void dfs(int r, int c, vector<vector<int>>& grid) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 1)
            return;

        grid[r][c] = 1;   // mark visited

        dfs(r + 1, c, grid);
        dfs(r - 1, c, grid);
        dfs(r, c + 1, grid);
        dfs(r, c - 1, grid);
    }
    int closedIsland(vector<vector<int>>& grid) {
       m = grid.size();
        n = grid[0].size();

        // Step 1: Remove boundary-connected islands
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0) dfs(i, 0, grid);
            if (grid[i][n - 1] == 0) dfs(i, n - 1, grid);
        }

        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 0) dfs(0, j, grid);
            if (grid[m - 1][j] == 0) dfs(m - 1, j, grid);
        }

        // Step 2: Count closed islands
        int count = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 0) {
                    count++;
                    dfs(i, j, grid);
                }
            }
        }

        return count; 
    }
};