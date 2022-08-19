// By Vishwam Shriram Mundada
// https://leetcode.com/problems/ones-and-zeroes/
// Decent

class Solution {
public:
    vector<vector<vector<int> > > dp;
    
    pair<int, int> count(string &s)
    {
        int o = 0;
        for(auto ch : s)
            if(ch == '1')
                o++;
        
        return {s.size()-o, o};
    }
    
    int rec(int idx, vector<pair<int, int> > &v, int m, int n, int cm, int cn)
    {
        if(idx == v.size())
            return 0;
        
        if(dp[idx][cm][cn] != -1)
            return dp[idx][cm][cn];
        
        int ans = rec(idx+1, v, m, n, cm, cn);
        
        if(cm + v[idx].first <= m && cn + v[idx].second <= n)
            ans = max(ans, rec(idx+1, v, m, n, cm + v[idx].first, cn + v[idx].second) + 1);
        
        return dp[idx][cm][cn] = ans;
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        dp.resize(strs.size()+1, vector<vector<int> >(m+1, vector<int>(n+1, -1)));
        vector<pair<int, int> > v(strs.size(), {0,0});
        for(int i = 0; i < strs.size(); ++i)
            v[i] = count(strs[i]);
        
        return rec(0, v, m, n, 0, 0);
    }
};
