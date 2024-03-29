// By Vishwam Shriram Mundada
// https://leetcode.com/problems/set-matrix-zeroes/
// Decent

/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.
You must do it in place.

Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

Constraints:
m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
 
Follow up:
A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) 
    {
        bool row = 0, col = 0;
        int n = mat.size(), m = mat[0].size();
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(mat[i][j] == 0)
                {
                    if(i == 0)
                        row = 1;
                    if(j == 0)
                        col = 1;
                    
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
        
        for(int i = 1; i < n; ++i)
            for(int j = 1; j < m; ++j)
            {
                if(mat[i][0] == 0)
                    mat[i][j] = 0;
                if(mat[0][j] == 0)
                    mat[i][j] = 0;
            }
        
        if(col)
            for(int i = 0; i < n; ++i)
                mat[i][0] = 0;
        
        if(row)
            for(int i = 0; i < m; ++i)
                mat[0][i] = 0;
    }
};
