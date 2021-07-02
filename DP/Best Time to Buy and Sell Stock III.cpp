// By Vishwam Shriram Mundada
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// Decent, 2 approaches

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at same time. You must sell before buying again.

Example 3:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

Example 4:
Input: prices = [1]
Output: 0

Constraints:
    1 <= prices.length <= 105
    0 <= prices[i] <= 105
*/

// App 1 :
// TC : O(N)
// SC : O(N)

class Solution {
public:    
    int dp[100001][5];
    
    int rec(int idx, vector<int>& prices, int cnt, int buy)
    {
        if(cnt == 0 || idx == prices.size())
            return 0;
        
        if(dp[idx][cnt] != -1)
            return dp[idx][cnt];
        
        int a1 = 0, a2 = 0, a3 = 0;
        
        if(!buy) // if not bought then buy
            a1 = rec(idx+1, prices, cnt-1, true) - prices[idx];
        
        else // if bought then sell
            a2 = rec(idx+1, prices, cnt-1, false) + prices[idx];
        
        // do nothing
        a3 = rec(idx+1, prices, cnt, buy);
        
        return dp[idx][cnt] = max(a1, max(a2, a3));
    }
    
    int maxProfit(vector<int>& prices) 
    {
        memset(dp, -1, sizeof(dp));
        return rec(0, prices, 4, false); // max 4 operations : buy->sell->buy->sell
    }
};


// App 2:
// TC : O(N)
// SC : O(1)
// REF : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/149383/Easy-DP-solution-using-state-machine-O(n)-time-complexity-O(1)-space-complexity

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int s1 = INT_MIN, s2 = INT_MIN, s3 = INT_MIN, s4 = INT_MIN;
        for(auto p : prices)
        {
            s1 = max(s1, -p);
            s2 = max(s2, s1+p);
            s3 = max(s3, s2-p);
            s4 = max(s4, s3+p);
        }
        return max(0, s4);
    }
};
