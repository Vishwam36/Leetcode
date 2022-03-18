// By Vishwam Shriram Mundada
// https://leetcode.com/problems/matrix-block-sum/
// Decent

/*
Given a m x n matrix mat and an integer k, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:
    i - k <= r <= i + k,
    j - k <= c <= j + k, and
    (r, c) is a valid position in the matrix.

Example 1:
Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
Output: [[12,21,16],[27,45,33],[24,39,28]]

Example 2:
Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
Output: [[45,45,45],[45,45,45],[45,45,45]]

Constraints:
    m == mat.length
    n == mat[i].length
    1 <= m, n, k <= 100
    1 <= mat[i][j] <= 100
*/

class Solution {
public:
    int n, m;
    
    vector<vector<int> > prefixSum(vector<vector<int>>& mat)
    {
        vector<vector<int> > pre(n, vector<int>(m, 0));
        for(int i = 0; i < n; ++i)
        {
            int sum = 0;
            for(int j = 0; j < m; ++j)
            {
                sum += mat[i][j];
                pre[i][j] = (i > 0 ? pre[i-1][j] + sum : sum);
            }
        }
        return pre;
    }
    
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) 
    {
        n = mat.size(), m = mat[0].size();
        auto pre = prefixSum(mat);
        auto ans = pre;
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                int li = max(i-k, 0);
                int lj = max(j-k, 0);
                int ui = min(i+k, n-1);
                int uj = min(j+k, m-1);
                
                ans[i][j] = pre[ui][uj] - (li == 0 ? 0 : pre[li-1][uj]) - (lj == 0 ? 0 : pre[ui][lj-1]) + ((li == 0 || lj == 0) ? 0 : pre[li-1][lj-1]);
            }
        }
        return ans;
    }
};
