// By Vishwam Shriram Mundada
// https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/
// Lengthy

/*
Given a m x n grid. Each cell of the grid represents a street. The street of grid[i][j] can be:
    1 which means a street connecting the left cell and the right cell.
    2 which means a street connecting the upper cell and the lower cell.
    3 which means a street connecting the left cell and the lower cell.
    4 which means a street connecting the right cell and the lower cell.
    5 which means a street connecting the left cell and the upper cell.
    6 which means a street connecting the right cell and the upper cell.

You will initially start at the street of the upper-left cell (0,0). A valid path in the grid is a path which starts from the upper left cell (0,0) 
and ends at the bottom-right cell (m - 1, n - 1). The path should only follow the streets.

Notice that you are not allowed to change any street.

Return true if there is a valid path in the grid or false otherwise.

Example 1:
Input: grid = [[2,4,3],[6,5,2]]
Output: true
Explanation: As shown you can start at cell (0, 0) and visit all the cells of the grid to reach (m - 1, n - 1).

Example 2:
Input: grid = [[1,2,1],[1,2,1]]
Output: false
Explanation: As shown you the street at cell (0, 0) is not connected with any street of any other cell and you will get stuck at cell (0, 0)

Example 3:
Input: grid = [[1,1,2]]
Output: false
Explanation: You will get stuck at cell (0, 1) and you cannot reach cell (0, 2).

Example 4:
Input: grid = [[1,1,1,1,1,1,3]]
Output: true

Example 5:
Input: grid = [[2],[2],[2],[2],[2],[2],[6]]
Output: true

Constraints:
    m == grid.length
    n == grid[i].length
    1 <= m, n <= 300
    1 <= grid[i][j] <= 6
*/

class Solution {
public:
    int n, m;
    vector<vector<int> > vis;
    
    char getDir(int x1, int y1, int x2, int y2) // what is direction of {x1, y1} -> {x2, y2}
    {
        if(x1 == x2)
        {
            if(y1 < y2)
                return 'l';
            else
                return 'r';
        }
        else
        {
            if(x1 < x2)
                return 'u';
            else
                return 'd';
        }
    }
    
    bool check(int srcx, int srcy, vector<vector<int>>& g)
    {
        vis = vector<vector<int> >(n, vector<int>(m, 0));
        vis[0][0] = 1;
        
        // I am using queue but queue will always have 1 element only, so without queue it can also be done
        queue<pair<int, int> > q;
        q.push({srcx, srcy});
        
        int prevx = 0, prevy = 0;
        
        while(!q.empty())
        {
            auto p = q.front(); q.pop();
            int x = p.first;
            int y = p.second;
                        
            if(prevx == n-1 && prevy == m-1)
                return true;
            if(x < 0 || x >= n || y < 0 || y >= m)
                continue;
            
            if(vis[x][y])
                continue;
            
            vis[x][y] = 1;
            
            char dir = getDir(prevx, prevy, x, y); // from which direction we have come to {x, y}
            
            if(dir == 'l' && (g[prevx][prevy] == 1 || g[prevx][prevy] == 4 || g[prevx][prevy] == 6))
            {
                if(g[x][y] == 1)
                    q.push({x+0, y+1});
                else if(g[x][y] == 3)
                    q.push({x+1, y+0});
                else if(g[x][y] == 5)
                    q.push({x-1, y});
            }
            else if(dir == 'r' && (g[prevx][prevy] == 1 || g[prevx][prevy] == 3 || g[prevx][prevy] == 5))
            {
                if(g[x][y] == 1)
                    q.push({x+0, y-1});
                else if(g[x][y] == 4)
                    q.push({x+1, y+0});
                else if(g[x][y] == 6)
                    q.push({x-1, y});
            }
            else if(dir == 'u' && (g[prevx][prevy] == 2 || g[prevx][prevy] == 4 || g[prevx][prevy] == 3))
            {
                if(g[x][y] == 2)
                    q.push({x+1, y});
                else if(g[x][y] == 5)
                    q.push({x, y-1});
                else if(g[x][y] == 6)
                    q.push({x, y+1});
            }
            else if(dir == 'd' && (g[prevx][prevy] == 2 || g[prevx][prevy] == 5 || g[prevx][prevy] == 6))
            {
                if(g[x][y] == 2)
                    q.push({x-1, y});
                else if(g[x][y] == 3)
                    q.push({x, y-1});
                else if(g[x][y] == 4)
                    q.push({x, y+1});
            }
            
            prevx = x;
            prevy = y;
        }
        return false;
    }
    
    bool hasValidPath(vector<vector<int>>& g) 
    {
        n = g.size(), m = g[0].size();
                
        if(g[0][0] == 1)
            return check(0, 1, g);
        
        if(g[0][0] == 2)
            return check(1, 0, g);
        
        if(g[0][0] == 3)
            return check(1, 0, g);
        
        if(g[0][0] == 4)
            return check(0, 1, g) || check(1, 0, g);
        
        if(g[0][0] == 5)
            return false;
        
        if(g[0][0] == 6)
            return check(0, 1, g);
        
        return false;
    }
};
