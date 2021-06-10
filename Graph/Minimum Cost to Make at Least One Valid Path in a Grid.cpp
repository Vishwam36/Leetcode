// By Vishwam Shriram Mundada
// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/
// Decent, dijkstra

/*
Given a m x n grid. Each cell of the grid has a sign pointing to the next cell you should visit if you are currently in this cell. The sign of grid[i][j] can be:

    1 which means go to the cell to the right. (i.e go from grid[i][j] to grid[i][j + 1])
    2 which means go to the cell to the left. (i.e go from grid[i][j] to grid[i][j - 1])
    3 which means go to the lower cell. (i.e go from grid[i][j] to grid[i + 1][j])
    4 which means go to the upper cell. (i.e go from grid[i][j] to grid[i - 1][j])

Notice that there could be some invalid signs on the cells of the grid which points outside the grid.

You will initially start at the upper left cell (0,0). A valid path in the grid is a path which starts from the upper left cell (0,0) and ends 
at the bottom-right cell (m - 1, n - 1) following the signs on the grid. The valid path doesn't have to be the shortest.

You can modify the sign on a cell with cost = 1. You can modify the sign on a cell one time only.

Return the minimum cost to make the grid have at least one valid path.

Example 1:
Input: grid = [[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]
Output: 3
Explanation: You will start at point (0, 0).
The path to (3, 3) is as follows. (0, 0) --> (0, 1) --> (0, 2) --> (0, 3) change the arrow to down with cost = 1 --> (1, 3) --> (1, 2) --> (1, 1) --> (1, 0) 
change the arrow to down with cost = 1 --> (2, 0) --> (2, 1) --> (2, 2) --> (2, 3) change the arrow to down with cost = 1 --> (3, 3)
The total cost = 3.

Example 2:
Input: grid = [[1,1,3],[3,2,2],[1,1,4]]
Output: 0
Explanation: You can follow the path from (0, 0) to (2, 2).

Example 3:
Input: grid = [[1,2],[4,3]]
Output: 1

Example 4:
Input: grid = [[2,2,2],[2,2,2]]
Output: 3

Example 5:
Input: grid = [[4]]
Output: 0

Constraints:
    m == grid.length
    n == grid[i].length
    1 <= m, n <= 100
*/

struct cmp
{
    bool operator()(vector<int> &a, vector<int> &b)
    {
        return a[2] >= b[2];
    }
};

class Solution {
public:
    int n, m;
    int di[4] = {0, 0, 1, -1};
    int dj[4] = {1, -1, 0, 0};
    
    bool isValid(int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    
    int minCost(vector<vector<int>>& grid) 
    {
        n = grid.size(), m = grid[0].size();
        vector<vector<int> > dist(n, vector<int>(m, INT_MAX));
        
        priority_queue<vector<int>, vector<vector<int> >, cmp> pq;
        pq.push({0, 0, 0});
        dist[0][0] = 0;
        
        while(!pq.empty())
        {
            auto v = pq.top(); pq.pop();
            int i = v[0];
            int j = v[1];
            int cost = v[2];
            
            if(i == n-1 && j == m-1)
                return cost;
            
            for(int k = 0; k < 4; ++k)
            {
                int newi = i + di[k];
                int newj = j + dj[k];
                
                if(isValid(newi, newj))
                {
                    if(dist[newi][newj] > cost && k+1 == grid[i][j])
                    {
                        dist[newi][newj] = min(dist[newi][newj], cost);
                        pq.push({newi, newj, dist[newi][newj]});
                    }
                    else if(dist[newi][newj] > cost+1)
                    {
                        dist[newi][newj] = min(dist[newi][newj], cost+1);
                        pq.push({newi, newj, dist[newi][newj]});
                    }
                }
            }
        }
        return -1;
    }
};
