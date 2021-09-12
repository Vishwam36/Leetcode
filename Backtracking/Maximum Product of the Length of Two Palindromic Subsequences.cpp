// By Vishwam Shriram Mundada
// https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/
// Decent, backtracking + DP

/*
Given a string s, find two disjoint palindromic subsequences of s such that the product of their lengths is maximized. The two subsequences are disjoint 
if they do not both pick a character at the same index.

Return the maximum possible product of the lengths of the two palindromic subsequences.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters. 
A string is palindromic if it reads the same forward and backward.

Example 1:
Input: s = "leetcodecom"
Output: 9
Explanation: An optimal solution is to choose "ete" for the 1st subsequence and "cdc" for the 2nd subsequence.
The product of their lengths is: 3 * 3 = 9.

Example 2:
Input: s = "bb"
Output: 1
Explanation: An optimal solution is to choose "b" (the first character) for the 1st subsequence and "b" (the second character) for the 2nd subsequence.
The product of their lengths is: 1 * 1 = 1.

Example 3:
Input: s = "accbcaxxcxx"
Output: 25
Explanation: An optimal solution is to choose "accca" for the 1st subsequence and "xxcxx" for the 2nd subsequence.
The product of their lengths is: 5 * 5 = 25.

Constraints:
    2 <= s.length <= 12
    s consists of lowercase English letters only.
*/

class Solution {
public:    
    int maxPalSubseq(string &s)
    {
        string t = s;
        reverse(t.begin(), t.end());
        
        int n = s.size();
        
        vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
        
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                
                dp[i][j] = max({dp[i][j], dp[i-1][j], dp[i][j-1]});
            }
        }
        return dp[n][n];
    }
    
    int ans = 0;
        
    void rec(int idx, string &str, string &s, string &t)
    {
        if(idx == str.size())
        {
            if(s.size() * t.size() <= ans)
                return;
            
            ans = max(ans, maxPalSubseq(s) * maxPalSubseq(t));
            return;
        }
        
        s.push_back(str[idx]);
        rec(idx+1, str, s, t);
        s.pop_back();
        
        t.push_back(str[idx]);
        rec(idx+1, str, s, t);
        t.pop_back();
    }
    
    int maxProduct(string s)
    {
        string t1 = "", t2 = "";
        rec(0, s, t1, t2);
        return ans;
    }
};
