// By Vishwam Shriram Mundada
// https://leetcode.com/problems/longest-common-subsequence/
// IMP

// App 1 : Recursive
// TC : O(N*M)
// SC : O(N*M)

class Solution {
public:
    vector<vector<int> > dp;
    
    int rec(int i, int j, string &t1, string &t2) // dont forget to put '&' otherwise it will give TLE
    {   
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(i == t1.size() || j == t2.size())
            return dp[i][j] = 0;
        
        if(t1[i] == t2[j])
            return dp[i][j] = rec(i+1, j+1, t1, t2) + 1;
        
        return dp[i][j] = max(rec(i+1, j, t1, t2), rec(i, j+1, t1, t2));
    }
    
    int longestCommonSubsequence(string text1, string text2) 
    {
        dp = vector<vector<int> > (text1.size()+1, vector<int>(text2.size()+1, -1));
        return rec(0, 0, text1, text2);
    }
};

// App 2 : Top-Down
// TC : O(N*M)
// SC : O(N*M)

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int n = text1.size(), m = text2.size();
        vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
        
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        
        return dp[n][m];
    }
};

// App 3 : Top-Down
// TC : O(N*M)
// SC : O(N)

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        vector<vector<int> > dp(2, vector<int>(text2.size()+1, 0));
        
        // Binary index, used to index current row and previous row.
        bool bi = 0;
        for(int i = 1; i <= text1.size(); ++i)
        {
            bi = i & 1;
            for(int j = 1; j <= text2.size(); ++j)
            {
                if(text1[i-1] == text2[j-1])
                    dp[bi][j] = dp[!bi][j-1] + 1;
                else
                    dp[bi][j] = max(dp[bi][j-1], dp[!bi][j]);
            }
        }
        return dp[bi][text2.size()];
    }
};
