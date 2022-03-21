// By Vishwam Shriram Mundada
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/109/backtracking/797/
// Easy

/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring.
The same letter cell may not be used more than once.

Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false

Constraints:
    m == board.length
    n = board[i].length
    1 <= m, n <= 6
    1 <= word.length <= 15
    board and word consists of only lowercase and uppercase English letters.
*/

class Solution {
public:
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};
    int n, m;
    vector<vector<bool> > vis;
    
    bool valid(int i, int j)
    {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    
    bool rec(int i, int j, int idx, vector<vector<char>>& board, string& word)
    {
        if(idx == word.size()-1)
            return true;
        
        for(int k = 0; k < 4; ++k)
        {
            int ni = i + di[k];
            int nj = j + dj[k];
            
            if(valid(ni,nj) && board[ni][nj] == word[idx+1] && !vis[ni][nj])
            {
                vis[ni][nj] = 1;
                if(rec(ni, nj, idx+1, board, word))
                    return true;
                vis[ni][nj] = 0;
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) 
    {
        n = board.size(), m = board[0].size();
        vis.resize(n, vector<bool>(m, false));
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(board[i][j] == word[0])
                {
                    vis[i][j] = true;
                    if(rec(i, j, 0, board, word))
                        return true;
                    vis[i][j] = false;
                }
        
        return false;
    }
};
