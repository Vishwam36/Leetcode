// By Vishwam Shriram Mundada
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/119/backtracking/856/
// Good 

/*
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:
Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

Constraints:
1 <= s.length <= 20
1 <= p.length <= 30
s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.
It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
*/

// https://www.youtube.com/watch?v=DJvw8jCmxUU&t=62s&ab_channel=Pepcoding

class Solution {
public:
    bool isMatch(string s, string p)
    {
        int n = p.size(), m = s.size();
        vector<vector<bool> > dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;
        for(int i = 1; i <= m; ++i)
            dp[0][i] = false;
        for(int i = 1; i <= n; ++i)
            dp[i][0] = (p[i-1] == '*' ? dp[i-2][0] : false);
        
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                if(p[i-1] == '*')
                    dp[i][j] = dp[i-2][j] || ((s[j-1] == p[i-2] || p[i-2] == '.') && dp[i][j-1]);
                else if(p[i-1] == s[j-1] || p[i-1] == '.')
                    dp[i][j] = dp[i-1][j-1];
        
        return dp[n][m];
    }
};
