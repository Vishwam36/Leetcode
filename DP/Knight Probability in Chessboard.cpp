// By Vishwam Shriram Mundada
// https://leetcode.com/problems/knight-probability-in-chessboard/
// Good, DP

/*
On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves. 
The rows and columns are 0-indexed, so the top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).

A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.

Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.

The knight continues moving until it has made exactly k moves or has moved off the chessboard.

Return the probability that the knight remains on the board after it has stopped moving.

Example 1:
Input: n = 3, k = 2, row = 0, column = 0
Output: 0.06250
Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
From each of those positions, there are also two moves that will keep the knight on the board.
The total probability the knight stays on the board is 0.0625.

Example 2:
Input: n = 1, k = 0, row = 0, column = 0
Output: 1.00000

Constraints:
    1 <= n <= 25
    0 <= k <= 100
    0 <= row, column <= n
*/



class Solution {
public:
    vector<vector<int> > dir = vector<vector<int> > ({{-2, -1}, {-1, -2}, {-2, 1}, {-1, 2}, {2, -1}, {1, -2}, {2, 1}, {1, 2}});
    vector<vector<vector<double> > > dp;
    
    bool valid(int r, int c, int n)
    {
        return r >= 0 && c >= 0 && r < n && c < n;
    }
    
    double rec(int r, int c, int n, int k)
    {
        if(k == 0)
            return 1;
        if(dp[r][c][k] != -1)
            return dp[r][c][k];
        
        double ans = 0;
        for(int i = 0; i < 8; ++i)
        {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            
            if(valid(nr, nc, n))
                ans += 0.125 * rec(nr, nc, n, k-1);
        }
        
        return ans;
    }
    
    double knightProbability(int n, int k, int row, int column)
    {
        dp = vector<vector<vector<double> > >(n, vector<vector<double> >(n, vector<double>(k+1, -1)));
        return rec(row, column, n, k);
    }
};
