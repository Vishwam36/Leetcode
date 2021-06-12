// By Vishwam Shriram Mundada
// https://leetcode.com/problems/largest-magic-square/
// Lengthy implementation

/*
A k x k magic square is a k x k grid filled with integers such that every row sum, every column sum, and both diagonal sums are all equal. 
The integers in the magic square do not have to be distinct. Every 1 x 1 grid is trivially a magic square.

Given an m x n integer grid, return the size (i.e., the side length k) of the largest magic square that can be found within this grid.

Example 1:
Input: grid = [[7,1,4,5,6],[2,5,1,6,4],[1,5,4,3,2],[1,2,7,3,4]]
Output: 3
Explanation: The largest magic square has a size of 3.
Every row sum, column sum, and diagonal sum of this magic square is equal to 12.
- Row sums: 5+1+6 = 5+4+3 = 2+7+3 = 12
- Column sums: 5+5+2 = 1+4+7 = 6+3+3 = 12
- Diagonal sums: 5+4+3 = 6+4+2 = 12

Example 2:
Input: grid = [[5,1,3,1],[9,3,3,1],[1,3,3,8]]
Output: 2

Constraints:
    m == grid.length
    n == grid[i].length
    1 <= m, n <= 50
    1 <= grid[i][j] <= 106
*/

class Solution {
public:
    bool can(vector<vector<int>>& grid, vector<vector<int>>& ver, vector<vector<int>>& hor, int tr, int lc, int br, int rc)
    {
        int sum = 0, tempSum = 0;
        if(tr > 0)
            sum = ver[br][lc]-ver[tr-1][lc];
        else
            sum = ver[br][lc];
        
        for(int i = lc; i <= rc; ++i) // for column sum
        {
            tempSum = 0;
            if(tr > 0)
                tempSum = ver[br][i]-ver[tr-1][i];
            else
                tempSum = ver[br][i];
            
            if(tempSum != sum)
                return false;
        }
        
        for(int i = tr; i <= br; ++i) // for row sum
        {
            tempSum = 0;
            if(lc > 0)
                tempSum = hor[i][rc]-hor[i][lc-1];
            else
                tempSum = hor[i][rc];
            
            if(tempSum != sum)
                return false;
        }
        
        tempSum = 0;
        int i = tr, j = lc;
        while(i <= br && j <= rc) // diagonal sum
            tempSum += grid[i++][j++];
        
        if(tempSum != sum)
            return false;
        
        tempSum = 0;
        i = tr, j = rc;
        while(i <= br && j >= lc) // diagonal sum
            tempSum += grid[i++][j--];
        
        if(tempSum != sum)
            return false;
        
        return true;
    }
    
    int largestMagicSquare(vector<vector<int>>& grid) 
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int> > ver = grid, hor = grid;
        
        for(int i = 0; i < n; ++i)
            for(int j = 1; j < m; ++j)
                hor[i][j] += hor[i][j-1];
        
        for(int j = 0; j < m; ++j)
            for(int i = 1; i < n; ++i)
                ver[i][j] += ver[i-1][j];
        
        int ans = 1;
        for(int tr = 0; tr < n; ++tr)
            for(int lc = 0; lc < m; ++lc)
                for(int size = ans+1; tr+size-1 < n && lc+size-1 < m; ++size)
                {
                    int br = tr+size-1;
                    int rc = lc+size-1;
                    
                    if(can(grid, ver, hor, tr, lc, br, rc))
                        ans = max(ans, size);
                }
        
        return ans;
    }
};
