// By Vishwam Shriram Mundada
// https://leetcode.com/problems/map-of-highest-peak/
// Standard, Decent

/*
You are given an integer matrix isWater of size m x n that represents a map of land and water cells.

If isWater[i][j] == 0, cell (i, j) is a land cell.
If isWater[i][j] == 1, cell (i, j) is a water cell.
You must assign each cell a height in a way that follows these rules:

The height of each cell must be non-negative.
If the cell is a water cell, its height must be 0.
Any two adjacent cells must have an absolute height difference of at most 1. 
A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).
Find an assignment of heights such that the maximum height in the matrix is maximized.

Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are multiple solutions, return any of them.

Example 1:
Input: isWater = [[0,1],[0,0]]
Output: [[1,0],[2,1]]
Explanation: The image shows the assigned heights of each cell.
The blue cell is the water cell, and the green cells are the land cells.

Example 2:
Input: isWater = [[0,0,1],[1,0,0],[0,0,0]]
Output: [[1,1,0],[0,1,1],[1,2,2]]
Explanation: A height of 2 is the maximum possible height of any assignment.
Any height assignment that has a maximum height of 2 while still meeting the rules will also be accepted.

Constraints:
m == isWater.length
n == isWater[i].length
1 <= m, n <= 1000
isWater[i][j] is 0 or 1.
There is at least one water cell.
*/

class Solution {
public:
    int n, m;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    bool isValid(int i, int j)
    {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) 
    {
        n = isWater.size(), m = isWater[0].size();
        vector<vector<bool> > vis(n, vector<bool> (m, 0));
        queue<pair<int, int> > q;
        
        vector<vector<int> > ans(n, vector<int>(m, INT_MAX));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(isWater[i][j] == 1)
                {
                    isWater[i][j] = 0;
                    q.push({i, j});
                    vis[i][j] = 1;
                }
                else
                {
                    isWater[i][j] = -1;
                }
        
        int peak = 1;
        while(!q.empty())
        {
            int len = q.size();
            for(int i = 0; i < len; ++i)
            {
                pair<int, int> p = q.front();
                q.pop();
                
                int x = p.first;
                int y = p.second;
                
                for(int i = 0; i < 4; ++i)
                {
                    int xx = x + dx[i];
                    int yy = y + dy[i];
                    
                    if(isValid(xx, yy) && !vis[xx][yy])
                    {
                        vis[xx][yy] = 1;
                        q.push({xx, yy});
                        isWater[xx][yy] = peak;
                    }
                }
            }
            peak++;
        }
        return isWater;
    }
};
