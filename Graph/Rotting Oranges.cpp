// By Vishwam Shriram Mundada
// https://leetcode.com/problems/rotting-oranges/
// Decent

class Solution {
public:
    static bool isValid(int x, int y, int n, int m)
    {
        if(x >= 0 && x < n && y >= 0 && y < m)
            return true;
        
        return false;
    }
        
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int a1[] = {-1, 0, 1, 0};
        int a2[] = {0, 1, 0, -1};
        
        int n = grid.size(), m = grid[0].size(), ans = 0, x, y, newX, newY, level, fresh = 0;
        
        queue<pair<pair<int, int>, int > > q;
            
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(grid[i][j] == 1)
                    fresh++;
                
                else if(grid[i][j] == 2)
                    q.push( { {i,j}, 0});
            }
        }
        
        if(fresh == 0)
            return 0;
        
        while(!q.empty())
        {
            pair<pair<int, int>, int > curr = q.front();
            q.pop();
                        
            x = curr.first.first;
            y = curr.first.second;
            level = curr.second;
            
            ans = max(ans, level);
            
            for(int i = 0; i < 4; ++i)
            {
                newX = x + a1[i];
                newY = y + a2[i];
                
                if(isValid(newX, newY, n, m) && grid[newX][newY] == 1)
                {
                    grid[newX][newY] = 2;
                    q.push( {{newX, newY}, level+1} );
                }
            }
        }
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(grid[i][j] == 1)
                    return -1;
        
        return ans;
    }
};
