// By Vishwam Shriram Mundada
// https://leetcode.com/problems/01-matrix/
// Easy

/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

Example 1:
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

Example 2:
Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]

Constraints:
    m == mat.length
    n == mat[i].length
    1 <= m, n <= 104
    1 <= m * n <= 104
    mat[i][j] is either 0 or 1.
    There is at least one 0 in mat.
*/

class Solution {
public:
    int n, m;
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, 1, -1};
    
    bool isValid(int i, int j)
    {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        n = mat.size(); m = mat[0].size();
        vector<vector<int> > ans(n, vector<int>(m, INT_MAX));
        // using queue to store position of elements whose answer we know, to use it to derive others' distances
        queue<pair<int, int> > q;
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(mat[i][j] == 0)
                {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
        
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int k = 0; k < 4; ++k)
            {
                int i = x + di[k];
                int j = y + dj[k];
                
                if(isValid(i, j) && ans[i][j] > ans[x][y]+1)
                {
                    ans[i][j] = ans[x][y]+1;
                    q.push({i, j});
                }
            }
        }
        
        return ans;
    }
};
