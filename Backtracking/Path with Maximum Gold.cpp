// By Vishwam Shriram Mundada
// https://leetcode.com/problems/path-with-maximum-gold/
// Decent, Checking all possibilities
/*
In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

Every time you are located in a cell you will collect all the gold in that cell.
From your position, you can walk one step to the left, right, up, or down.
You can't visit the same cell more than once.
Never visit a cell with 0 gold.
You can start and stop collecting gold from any position in the grid that has some gold.
 
Example 1:
Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
Output: 24
Explanation:
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Path to get the maximum gold, 9 -> 8 -> 7.

Example 2:
Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
Output: 28
Explanation:
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.
*/

class Solution {
public:
    int maxGold = INT_MIN, n, m;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    bool isValid(int x, int y)
    {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    
    void rec(int x, int y, vector<vector<int>>& grid, vector<vector<bool> > &vis, int sum)
    {
        maxGold = max(sum, maxGold);
        
        for(int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(isValid(nx, ny) && !vis[nx][ny] && grid[nx][ny] != 0)
            {
                vis[nx][ny] = 1;
                rec(nx, ny, grid, vis, sum + grid[nx][ny]);
                vis[nx][ny] = 0;
            }
        }
    }
    
    int getMaximumGold(vector<vector<int>>& grid) 
    {
        n = grid.size(), m = grid[0].size();
        maxGold = INT_MIN;
        
        vector<vector<bool> > vis(n, vector<bool>(m, 0));
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(grid[i][j] == 0)
                    continue;
                
                vis[i][j] = 1;
                rec(i, j, grid, vis, grid[i][j]);
                vis[i][j] = 0;
            }
        }
        return maxGold;
    }
};
