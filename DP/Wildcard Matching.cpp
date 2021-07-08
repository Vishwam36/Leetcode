// By Vishwam Shriram Mundada
// https://leetcode.com/problems/wildcard-matching/
// Decent
// REF : https://www.youtube.com/watch?v=NbgUZAoIz3g
// Recursion + Memoization fails here

/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

    '?' Matches any single character.
    '*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.

Example 3:
Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

Example 4:
Input: s = "adceb", p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".

Example 5:
Input: s = "acdcb", p = "a*c?b"
Output: false

Constraints:
    0 <= s.length, p.length <= 2000
    s contains only lowercase English letters.
    p contains only lowercase English letters, '?' or '*'.
*/

class Solution {
public:
    bool isMatch(string s, string p) 
    {
        int n = s.size(), m = p.size();
        bool dp[n+1][m+1];
        
        dp[n][m] = 1; // match blank pattern with blank string
        // match blank string with some pattern
        for(int i = m-1; i >= 0; --i)
            if(p[i] == '*')
                dp[n][i] = dp[n][i+1];
            else
                dp[n][i] = 0;
        
        // match blank pattern with some string
        for(int i = n-1; i >= 0; --i)
            dp[i][m] = 0;
        
        for(int i = n-1; i >= 0; --i)
            for(int j = m-1; j >= 0; --j)
            {
                if(p[j] == '?')
                    dp[i][j] = dp[i+1][j+1];
                else if(p[j] == '*')
                    dp[i][j] = dp[i+1][j] || dp[i][j+1];
                else
                    dp[i][j] = dp[i+1][j+1] && s[i] == p[j];
            }
        
        return dp[0][0];
    }
};
