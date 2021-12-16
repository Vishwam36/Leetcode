// By Vishwam Shriram Mundada
// https://leetcode.com/problems/valid-parenthesis-string/
// Easy

/*
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

    Any left parenthesis '(' must have a corresponding right parenthesis ')'.
    Any right parenthesis ')' must have a corresponding left parenthesis '('.
    Left parenthesis '(' must go before the corresponding right parenthesis ')'.
    '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "(*)"
Output: true

Example 3:
Input: s = "(*))"
Output: true

Constraints:
    1 <= s.length <= 100
    s[i] is '(', ')' or '*'.
*/

class Solution {
public:
    int dp[101][101][101];
    
    bool rec(int idx, int open, int close, string &s)
    {
        if(close > open)
            return 0;
        if(idx == s.size())
            return open == close;
        if(dp[idx][open][close] != -1)
            return dp[idx][open][close];
        
        int ans = -1;
        if(s[idx] == '(')
            ans = rec(idx+1, open+1, close, s);
        
        else if(s[idx] == ')')
            ans = rec(idx+1, open, close+1, s);
        
        else
            ans = rec(idx+1, open, close, s) || rec(idx+1, open+1, close, s) || rec(idx+1, open, close+1, s);
        
        return dp[idx][open][close] = ans;
    }
    
    bool checkValidString(string s) 
    {
        memset(dp, -1, sizeof(dp));
        return rec(0, 0, 0, s);
    }
};
