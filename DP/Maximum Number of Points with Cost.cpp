// By Vishwam Shriram Mundada
// https://leetcode.com/problems/maximum-number-of-points-with-cost/
// Decent

/*
You are given an m x n integer matrix points (0-indexed). Starting with 0 points, you want to maximize the number of points you can get from the matrix.

To gain points, you must pick one cell in each row. Picking the cell at coordinates (r, c) will add points[r][c] to your score.

However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. For every two adjacent rows r and r + 1 
(where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from your score.

Return the maximum number of points you can achieve.

Example 1:
Input: points = [[1,2,3],[1,5,1],[3,1,1]]
Output: 9
Explanation:
The blue cells denote the optimal cells to pick, which have coordinates (0, 2), (1, 1), and (2, 0).
You add 3 + 5 + 3 = 11 to your score.
However, you must subtract abs(2 - 1) + abs(1 - 0) = 2 from your score.
Your final score is 11 - 2 = 9.

Example 2:
Input: points = [[1,5],[2,3],[4,2]]
Output: 11
Explanation:
The blue cells denote the optimal cells to pick, which have coordinates (0, 1), (1, 1), and (2, 0).
You add 5 + 3 + 4 = 12 to your score.
However, you must subtract abs(1 - 1) + abs(1 - 0) = 1 from your score.
Your final score is 12 - 1 = 11.

Constraints:
    m == points.length
    n == points[r].length
    1 <= m, n <= 105
    1 <= m * n <= 105
    0 <= points[r][c] <= 105
*/

// REF : https://www.youtube.com/watch?v=STEJHYc9rMw

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points)
    {
        int n = points.size(), m = points[0].size();
        
        vector<long long> dp(m);
        for(int i = 0; i < m; ++i)
            dp[i] = points[0][i];
        
        vector<long long> left(m, 0), right(m, 0);
        
        for(int i = 1; i < n; ++i)
        {
            left[0] = dp[0];
            for(int j = 1; j < m; ++j)
                left[j] = max(left[j-1]-1, dp[j]);
            
            right[m-1] = dp[m-1];
            for(int j = m-2; j >= 0; --j)
                right[j] = max(right[j+1]-1, dp[j]);
            
            for(int j = 0; j < m; ++j)
                dp[j] = max(left[j], right[j]) + points[i][j];
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};
