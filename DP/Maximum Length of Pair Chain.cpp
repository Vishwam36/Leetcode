// By Vishwam Shriram Mundada
// https://leetcode.com/problems/maximum-length-of-pair-chain/
// Easy

/*
You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.

A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.

Return the length longest chain which can be formed.

You do not need to use up all the given intervals. You can select pairs in any order.

Example 1:
Input: pairs = [[1,2],[2,3],[3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4].

Example 2:
Input: pairs = [[1,2],[7,8],[4,5]]
Output: 3
Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].

Constraints:
    n == pairs.length
    1 <= n <= 1000
    -1000 <= lefti < righti < 1000
*/

// App 1 : Recursion + Memoization
// TC : O(N^2)
// SC : O(N^2)

class Solution {
public:
    int dp[1001][2001];
    
    int rec(int index, int reach, vector<vector<int>>& pairs)
    {
        if(index >= pairs.size())
            return 0;
        
        if(dp[index][reach] != -1)
            return dp[index][reach];
        
        int take = 0, not_take = 0;
        
        if(pairs[index][0] > reach)
            take = rec(index+1, pairs[index][1], pairs) + 1;
        
        not_take = rec(index+1, reach, pairs);
        
        return dp[index][reach] = max(take, not_take);
    }
    
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        sort(pairs.begin(), pairs.end());
        
        memset(dp, -1, sizeof(dp));
        // add 1000 to get all positive values because we are using dp array
        for(int i = 0; i < pairs.size(); ++i)
        {
            pairs[i][0] += 1000;
            pairs[i][1] += 1000;
        }
        return rec(0, 0, pairs);
    }
};

// App 2 : Top-Down
// TC : O(N^2)
// SC : O(N)

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        
        vector<int> dp(n, 0);
        dp[0] = 1;
        for(int i = 1; i < n; ++i)
        {
            dp[i] = dp[i-1];
            for(int j = 0; j < i; ++j)
                if(pairs[i][0] > pairs[j][1])
                    dp[i] = max(dp[i], dp[j]+1);
        }
        return dp[n-1];
    }
};
