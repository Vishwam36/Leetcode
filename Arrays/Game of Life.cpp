// By Vishwam Shriram Mundada
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/831/
// Easy

/*
According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). 
Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

    Any live cell with fewer than two live neighbors dies as if caused by under-population.
    Any live cell with two or three live neighbors lives on to the next generation.
    Any live cell with more than three live neighbors dies, as if by over-population.
    Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. 
Given the current state of the m x n grid board, return the next state.

Example 1:
Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]

Example 2:
Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]

Constraints:
    m == board.length
    n == board[i].length
    1 <= m, n <= 25
    board[i][j] is 0 or 1.
*/

class Solution {
public:
    int n, m;
    int di[8] = {0, 0, 1, -1, 1, 1, -1, -1};
    int dj[8] = {1, -1, 0, 0, 1, -1, 1, -1};
    
    bool valid(int i, int j)
    {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    
    int neighbours(int i, int j, vector<vector<int>>& board)
    {
        int ans = 0;
        for(int k = 0; k < 8; ++k)
        {
            int ni = i + di[k];
            int nj = j + dj[k];
            
            if(valid(ni, nj) && board[ni][nj] >= 1)
                ans++;
        }
        return ans;
    }
    
    void gameOfLife(vector<vector<int>>& board)
    {
        n = board.size(), m = board[0].size();
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                int nei = neighbours(i, j, board);
                if(board[i][j] >= 1)
                {
                    if(nei <= 1)
                        board[i][j] = 2;
                    else if(nei >= 4)
                        board[i][j] = 2;
                }
                else
                {
                    if(nei == 3)
                        board[i][j] = -1;
                }
            }
        }
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(board[i][j] == 2)
                    board[i][j] = 0;
                else if(board[i][j] == -1)
                    board[i][j] = 1;
    }
};
