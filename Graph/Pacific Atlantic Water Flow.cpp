// By Vishwam Shriram Mundada
// https://leetcode.com/problems/pacific-atlantic-water-flow/
// Good question

/*
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic 
Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell 
at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or 
equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

Example 1:
Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]

Example 2:
Input: heights = [[2,1],[1,2]]
Output: [[0,0],[0,1],[1,0],[1,1]]

Constraints:
m == heights.length
n == heights[r].length
1 <= m, n <= 200
0 <= heights[r][c] <= 10^5
*/

class Solution {
public:
    int n, m;
    
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};
    
    bool isValid(int i, int j)
    {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    
    void fillVis(vector<vector<bool> > &vis, vector<vector<int>>& heights)
    {
        queue<pair<int, int> > q;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(vis[i][j])
                    q.push({i, j});
        
        while(!q.empty())
        {
            auto p = q.front(); q.pop();
            int x = p.first;
            int y = p.second;
            
            for(int k = 0; k < 4; ++k)
            {
                int i = x + di[k];
                int j = y + dj[k];
                
                if(isValid(i, j) && !vis[i][j] && heights[i][j] >= heights[x][y])
                {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        n = heights.size(), m = heights[0].size();
        vector<vector<bool> > visAtla(n, vector<bool>(m, false));
        vector<vector<bool> > visPaci(n, vector<bool>(m, false));
        
        for(int i = 0; i < m; ++i)
            visPaci[0][i] = 1;
        for(int i = 0; i < n; ++i)
            visPaci[i][0] = 1;
        
        fillVis(visPaci, heights);
        
        for(int i = 0; i < m; ++i)
            visAtla[n-1][i] = 1;
        for(int i = 0; i < n; ++i)
            visAtla[i][m-1] = 1;
        
        fillVis(visAtla, heights);
        
        vector<vector<int> > ans;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(visAtla[i][j] && visPaci[i][j])
                    ans.push_back({i, j});
        
        return ans;
    }
};
