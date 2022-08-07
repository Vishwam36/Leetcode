// By Vishwam Shriram Mundada
// https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/
// Easy DP

class Solution {
public:
    int n;
    vector<int> dp;
    
    bool rec(int i, vector<int> &v)
    {
        if(i == n)
            return true;
        if(i == n-1)
            return false;
        
        if(dp[i] != -1)
            return dp[i];
        
        bool ans = false;
        
        if(i+1 < n)
            if(v[i] == v[i+1])
                ans = ans || rec(i+2, v);
        
        if(i+2 < n)
        {
            if(v[i] == v[i+1] && v[i+1] == v[i+2])
                ans = ans | rec(i+3, v);
            if(v[i+2] - v[i+1] == 1 && v[i+1] - v[i] == 1)
                ans = ans | rec(i+3, v);
        }
        
        return dp[i] = ans;
    }
    
    bool validPartition(vector<int>& v) 
    {
        n = v.size();
        dp.resize(n+1, -1);
        return rec(0, v);
    }
};
