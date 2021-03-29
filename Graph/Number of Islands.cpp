// By Vishwam Shriram Mundada
// https://leetcode.com/problems/number-of-islands/
// Easy

class Solution {
public:
    int a[4] = {0 ,-1, 0, 1};
    int b[4] = {-1, 0, 1, 0};
    int n = 0, m = 0;
    
    static bool isValid(int x, int y, int n, int m)
    {
        return x >= 0 && y >= 0 && x < n && y < m;
    }
    
    void bfs(pair<int, int> source, vector<vector<char>>& grid, vector<vector<bool> > &visited)
    {
        queue<pair<int, int> > q;
        q.push(source);
        visited[source.first][source.second] = true;
        
        while(!q.empty())
        {
            pair<int, int> curr = q.front();
            q.pop();
            
            for(int i = 0; i < 4; ++i)
            {
                int x = curr.first + a[i];
                int y = curr.second + b[i];
                
                if(isValid(x, y, n, m) && !visited[x][y] && grid[x][y] == '1')
                {
                    q.push({x,y});
                    visited[x][y] = true;
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        vector<vector<bool> > visited(n, vector<bool>(m, false));
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(grid[i][j] == '1' && !visited[i][j])
                {
                    bfs(make_pair(i, j), grid, visited);
                    ++ans;
                }
            }
        }
        return ans;
    }
};
