// By Vishwam Shriram Mundada
// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
// Decent

class Solution {
public:
    int rec(int l, int r, vector<int> &cuts, vector<vector<int> > &dp)
    {
        if(r-l <= 1)
            return 0;
        if(dp[l][r] != -1)
            return dp[l][r];
        
        int ans = INT_MAX;
        for(int i = l+1; i <= r-1; ++i)
            ans = min(ans, rec(l, i, cuts, dp) + rec(i, r, cuts, dp) + cuts[r]-cuts[l]);
        
        return dp[l][r] = ans;
    }
    
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        vector<vector<int> > dp(cuts.size(), vector<int>(cuts.size(), -1));
        return rec(0, cuts.size()-1, cuts, dp);
    }
};
