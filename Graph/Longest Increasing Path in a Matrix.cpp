// By Vishwam Shriram Mundada
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/118/trees-and-graphs/849/
// Decent

/*
Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary 
(i.e., wrap-around is not allowed).

Example 1:
Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].

Example 2:
Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

Example 3:
Input: matrix = [[1]]
Output: 1

Constraints:
    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 200
    0 <= matrix[i][j] <= 2^31 - 1
*/

class Solution {
public:
    int n, m;
    vector<vector<int> > v;
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};
    
    bool valid(int i, int j)
    {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    
    int dfs(int x, int y, vector<vector<int>>& mat)
    {
        if(v[x][y] != -1)
            return v[x][y];
        
        int ans = 1;
        
        for(int k = 0; k < 4; ++k)
        {
            int i = x + di[k];
            int j = y + dj[k];
            
            if(valid(i, j) && mat[i][j] > mat[x][y])
                ans = max(ans, 1 + dfs(i, j, mat));
        }
        
        return v[x][y] = ans;
    }
    
    int longestIncreasingPath(vector<vector<int>>& mat) 
    {
        n = mat.size(), m = mat[0].size();
        v.resize(n, vector<int>(m, -1));
        
        int ans = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
            {
                dfs(i, j, mat);
                ans = max(ans, v[i][j]);
            }
        
        return ans;
    }
};
