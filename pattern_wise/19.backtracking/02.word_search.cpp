//date-14/2/26
//link-https://leetcode.com/problems/word-search/
/*Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true*/

//code-
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
       int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
         }
    
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index) {
        if(index == word.length())
            return true;
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() 
           || board[i][j] != word[index])
            return false;
        
        char temp = board[i][j];
        board[i][j] = '#';
        bool found = dfs(board, word, i+1, j, index+1) ||
                     dfs(board, word, i-1, j, index+1) ||
                     dfs(board, word, i, j+1, index+1) ||
                     dfs(board, word, i, j-1, index+1);
        board[i][j] = temp;
        return found;  
    }
};