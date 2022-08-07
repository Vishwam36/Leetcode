// By Vishwam Shriram Mundada
// https://leetcode.com/problems/longest-ideal-subsequence/
// Easy

class Solution {
public:
    int n;
    vector<vector<int> > dp;
    
    int rec(int idx, string &s, int k, char ch)
    {
        if(idx == n)
            return 0;
        
        if(dp[idx][ch] != -1)
            return dp[idx][ch];
        
        int ans = rec(idx+1, s, k, ch);
        if(ch == ' ' || abs(ch-s[idx]) <= k)
            ans = max(ans, rec(idx+1, s, k, s[idx]) + 1);
        
        return dp[idx][ch] = ans;
    }
    
    int longestIdealString(string s, int k) 
    {
        n = s.size();
        dp.resize(n+1, vector<int>(256, -1));
        return rec(0, s, k, ' ');
    }
};
