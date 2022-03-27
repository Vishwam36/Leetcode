// By Vishwam Shriram Mundada
// https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/
// Decent

/*
There are n piles of coins on a table. Each pile consists of a positive number of coins of assorted denominations.

In one move, you can choose any coin on top of any pile, remove it, and add it to your wallet.

Given a list piles, where piles[i] is a list of integers denoting the composition of the ith pile from top to bottom, and a positive integer k, 
return the maximum total value of coins you can have in your wallet if you choose exactly k coins optimally.

Example 1:
Input: piles = [[1,100,3],[7,8,9]], k = 2
Output: 101
Explanation:
The above diagram shows the different ways we can choose k coins.
The maximum total we can obtain is 101.

Example 2:
Input: piles = [[100],[100],[100],[100],[100],[100],[1,1,1,1,1,1,700]], k = 7
Output: 706
Explanation:
The maximum total can be obtained if we choose all coins from the last pile.

Constraints:
    n == piles.length
    1 <= n <= 1000
    1 <= piles[i][j] <= 105
    1 <= k <= sum(piles[i].length) <= 2000
*/

class Solution {
public:
    vector<vector<int> > dp;
    
    int rec(int idx, vector<vector<int>>& piles, int k)
    {
        if(k == 0 || idx == piles.size())
            return 0;
        
        if(dp[idx][k] != -1)
            return dp[idx][k];
        
        int ans = rec(idx+1, piles, k);
        
        for(int i = 0; i < min(k, (int)piles[idx].size()); ++i)
            ans = max(ans, rec(idx+1, piles, k-(i+1)) + piles[idx][i]);
        
        return dp[idx][k] = ans;
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) 
    {
        dp.resize(piles.size()+1, vector<int>(k+1, -1));
        
        for(int i = 0; i < piles.size(); ++i)
            for(int j = 1; j < piles[i].size(); ++j)
                piles[i][j] += piles[i][j-1];
        
        return rec(0, piles, k);
    }
};
