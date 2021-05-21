// By Vishwam Shriram Mundada
// https://leetcode.com/problems/interleaving-string/
// 2nd Approach is Good

/*
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:
    s = s1 + s2 + ... + sn
    t = t1 + t2 + ... + tm
    |n - m| <= 1
    The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...

Note: a + b is the concatenation of strings a and b.

Example 1:
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true

Example 2:
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false

Example 3:
Input: s1 = "", s2 = "", s3 = ""
Output: true

Constraints:
    0 <= s1.length, s2.length <= 100
    0 <= s3.length <= 200
    s1, s2, and s3 consist of lowercase English letters.
*/

// App 1 : Space : O(n^2)

class Solution {
public:
    int dp[101][101];
    
    int rec(int index, int i, int j, string s1, string s2, string s3)
    {
        if(index == s3.size())
            return 1;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(i < s1.size() && j < s2.size() && s3[index] == s1[i] && s3[index] == s2[j])
            return dp[i][j] = rec(index+1, i+1, j, s1, s2, s3) || rec(index+1, i, j+1, s1, s2, s3);
        
        if(i < s1.size() && s3[index] == s1[i])
            return dp[i][j] = rec(index+1, i+1, j, s1, s2, s3);
        
        if(j < s2.size() && s3[index] == s2[j])
            return dp[i][j] = rec(index+1, i, j+1, s1, s2, s3);
        
        else
            return dp[i][j] = 0;
    }
    
    bool isInterleave(string s1, string s2, string s3) 
    {
        if(s1.size() + s2.size() != s3.size())
            return false;
        
        memset(dp, -1, sizeof(dp));
        return rec(0, 0, 0, s1, s2, s3);
    }
};

// App 2 : Space : O(n)
// Good approach

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
        int n = s1.size();
        int m = s2.size();
        if(s3.size() != n+m)
            return false;
        
        int dp[m+1];
        dp[0] = true;
        
        for(int i = 0; i <= n; ++i)
        {
            for(int j = 0; j <= m; ++j)
            {
                if(i == 0 && j == 0)
                    continue;
                
                if(i == 0)
                {
                    if(s2[j-1] == s3[i+j-1] && dp[j-1])
                        dp[j] = true;
                    else
                        dp[j] = false;
                }
                else if(j == 0)
                {
                    if(s1[i-1] == s3[i+j-1] && dp[0])
                        dp[0] = true;
                    else
                        dp[0] = false;
                }
                else
                {
                    if((s1[i-1] == s3[i+j-1] && dp[j]) || (s2[j-1] == s3[i+j-1] && dp[j-1]))
                        dp[j] = true;
                    else
                        dp[j] = false;
                }
            }
        }
        return dp[m];
    }
};
