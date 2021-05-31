// By Vishwam Shriram Mundada
// https://leetcode.com/problems/coin-change/
// Unbounded Knapsack variation

/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:
Input: coins = [2], amount = 3
Output: -1

Example 3:
Input: coins = [1], amount = 0
Output: 0

Example 4:
Input: coins = [1], amount = 1
Output: 1

Example 5:
Input: coins = [1], amount = 2
Output: 2

Constraints:
    1 <= coins.length <= 12
    1 <= coins[i] <= 231 - 1
    0 <= amount <= 104
*/

// App 1 : Top-Down

class Solution {
public:
    int MAX = 10005;
    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();
        int dp[n+1][amount+1];
        
        for(int i = 0; i <= n; ++i)
            for(int j = 0; j <= amount; ++j)
                if(j == 0)
                    dp[i][j] = 0; // we can always make 0 amount with 0 coins
                else
                    dp[i][j] = MAX;
        
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= amount; ++j)
            {
                int include = MAX;
                int not_include = dp[i-1][j];
                
                if(j-coins[i-1] >= 0)
                    include = dp[i][j-coins[i-1]] + 1;
                
                dp[i][j] = min(include, not_include);
            }
        }
        
        return dp[n][amount] >= MAX ? -1 : dp[n][amount];
    }
};

// Recursion + memoization

class Solution {
public:
    int n;
    int MAX = 10005;
    int dp[13][10005];
    
    int rec(int idx, int sum, vector<int> &coins, int amount)
    {
        if(idx >= coins.size() && sum < amount)
            return MAX;
        
        if(idx >= coins.size() && sum == amount)
            return 0;
        
        if(dp[idx][sum] != -1)
            return dp[idx][sum];
        
        int include = MAX;
        if((long long)sum+coins[idx] <= amount)
            include = rec(idx, sum+coins[idx], coins, amount) + 1;
        
        int not_include = rec(idx+1, sum, coins, amount);
        
        return dp[idx][sum] = min(include, not_include);
    }
    
    int coinChange(vector<int>& coins, int amount) 
    {
        memset(dp, -1, sizeof(dp));
        
        int ans = rec(0, 0, coins, amount);
        return ans >= MAX ? -1 : ans;
    }
};
