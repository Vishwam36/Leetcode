// By Vishwam Shriram Mundada
// https://leetcode.com/problems/edit-distance/
// Easy

class Solution {
public:
    int n1, n2;
    vector<vector<int> > dp;
    
    int rec(int i, int j, string &w1, string &w2)
    {
        if(i == w1.size())
            return w2.size()-j;
        else if(j == w2.size())
            return w1.size()-i;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = INT_MAX;
        if(w1[i] == w2[j])
            ans = min(ans, rec(i+1, j+1, w1, w2));
        
        ans = min(ans, rec(i+1, j+1, w1, w2)+1);
        ans = min(ans, rec(i+1, j, w1, w2)+1);
        ans = min(ans, rec(i, j+1, w1, w2)+1);
        
        return dp[i][j] = ans;
    }
    
    int minDistance(string w1, string w2) 
    {
        n1 = w1.size(), n2 = w2.size();
        dp.resize(n1+1, vector<int>(n2, -1));
        return rec(0, 0, w1, w2);
    }
};
