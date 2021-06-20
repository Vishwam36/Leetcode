// By Vishwam Shriram Mundada
// https://leetcode.com/problems/count-sub-islands/
// Decent, extension of standard count islands problem

/*
You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). 
An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.

An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.

Return the number of islands in grid2 that are considered sub-islands.

Example 1:
Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
Output: 3
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.

Example 2:
Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
Output: 2 
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are two sub-islands.

Constraints:
    m == grid1.length == grid2.length
    n == grid1[i].length == grid2[i].length
    1 <= m, n <= 500
    grid1[i][j] and grid2[i][j] are either 0 or 1.
*/

class Solution {
public:
    vector<vector<pair<int, int> > > islands;
    int n, m;
    vector<vector<bool> > vis;
    
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};
    
    bool isValid(int i, int j)
    {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    
    void giveIsland(int srcx, int srcy, vector<vector<int>>& g2)
    {
        vector<pair<int, int> > v;
        
        queue<pair<int, int> > q;
        q.push({srcx, srcy});
        vis[srcx][srcy] = 1;
        
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            v.push_back({x, y});
            
            for(int k = 0; k < 4; ++k)
            {
                int i = x + di[k];
                int j = y + dj[k];
                
                if(isValid(i, j) && !vis[i][j] && g2[i][j])
                {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        islands.push_back(v);
    }
    
    bool check(vector<pair<int, int> > &v, vector<vector<int>>& g1)
    {
        for(auto& p : v)
            if(g1[p.first][p.second] == 0)
                return false;
        
        return true;
    }
    
    int countSubIslands(vector<vector<int>>& g1, vector<vector<int>>& g2) 
    {
        n = g1.size(), m = g1[0].size();
        vis = vector<vector<bool> >(n, vector<bool>(m, false));
        
        for(int i = 0; i < n; ++i)
            for(int j =0; j < m; ++j)
                if(!vis[i][j] && g2[i][j])
                    giveIsland(i, j, g2);
        
        int ans = 0;
        for(auto& v : islands)
            if(check(v, g1))
                ans++;
        
        return ans;
    }
};
