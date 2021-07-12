// By Vishwam Shriram Mundada
// https://leetcode.com/problems/painting-a-grid-with-three-different-colors/
// Good question
// REF : https://www.youtube.com/watch?v=9ccqkYrH3JM&t=201s

/*
You are given two integers m and n. Consider an m x n grid where each cell is initially white. You can paint each cell red, green, or blue. All cells must be painted.

Return the number of ways to color the grid with no two adjacent cells having the same color. Since the answer can be very large, return it modulo 109 + 7.

Example 1:
Input: m = 1, n = 1
Output: 3
Explanation: The three possible colorings are shown in the image above.

Example 2:
Input: m = 1, n = 2
Output: 6
Explanation: The six possible colorings are shown in the image above.

Example 3:
Input: m = 5, n = 5
Output: 580986

Constraints:
    1 <= m <= 5
    1 <= n <= 1000
*/

// REF : https://www.youtube.com/watch?v=9ccqkYrH3JM&t=201s

// Color numbers I am taking are 0, 1, 2
// say 0 -> RED, 1 -> GREEN, 2 -> BLUE

class Solution {
public:
    const long long MOD = 1000000007;
    long long dp[5001][700];
    
    int getColor(int mask, int idx)
    {
        return ((mask >> (2*idx)) & 3);
    }
    
    int setColor(int mask, int idx, int newColor)
    {
        int oldColor = getColor(mask, idx);
        mask = ((mask) ^ (oldColor << (2*idx))); // subtract old color
        mask = ((mask) | (newColor << (2*idx))); // set new color
        return mask;
    }
    
    long long rec(int pos, int lastRow, int m, int n)
    {
        if(pos == m*n)
            return 1;
        
        if(dp[pos][lastRow] != -1)
            return dp[pos][lastRow];
        
        int i = pos / m;
        int j = pos % m;
        
        int neighbour1 = -1, neighbour2 = -1;
        // lastRow = curRowColor from 0 to  j-1 + lastRowColor from j to m-1
        if(i > 0)
            neighbour1 = getColor(lastRow, j);
        if(j > 0)
            neighbour2 = getColor(lastRow, j-1);
        
        long long ans = 0;
        for(int color = 0; color <= 2; ++color)
            if(color != neighbour1 && color != neighbour2)
            {
                int newRow = setColor(lastRow, j, color);
                ans = (ans + (dp[pos+1][newRow] == -1 ? rec(pos+1, newRow, m, n) : dp[pos+1][newRow])) % MOD;
            }
        
        return dp[pos][lastRow] = ans;
    }
    
    int colorTheGrid(int m, int n)
    {
        memset(dp, -1, sizeof(dp));
        return rec(0, 0, m, n);
    }
};
