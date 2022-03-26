// By Vishwam Shriram Mundada
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/121/dynamic-programming/862/
// Easy

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like 
(i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

    After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

Example 2:
Input: prices = [1]
Output: 0

Constraints:
    1 <= prices.length <= 5000
    0 <= prices[i] <= 1000
*/

class Solution {
public:
    vector<vector<int> > dp;
    
    int rec(int idx, vector<int>& prices, bool bought)
    {
        if(idx >= prices.size())
            return 0;
        
        if(dp[idx][bought] != -1)
            return dp[idx][bought];
        
        int ans = rec(idx+1, prices, bought);
        if(bought)
            ans = max(ans, rec(idx+2, prices, false) + prices[idx]);
        else
            ans = max(ans, rec(idx+1, prices, true) - prices[idx]);
        
        return dp[idx][bought] = ans;
    }
    
    int maxProfit(vector<int>& prices) 
    {
        dp.resize(prices.size()+1, vector<int>(2, -1));
        return rec(0, prices, false);
    }
};
