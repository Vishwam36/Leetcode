// By Vishwam Shriram Mundada
// https://leetcode.com/problems/longest-palindromic-substring/
// Decent

/*
Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"

Example 3:
Input: s = "a"
Output: "a"

Example 4:
Input: s = "ac"
Output: "a"
 
Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case),
*/

class Solution {
public:
    bool dp[1001][1001];
    int l = 0, size = 0;
    
    void setSize(int x, int y)
    {
        if(size < y-x+1)
        {
            l = x;
            size = y-x+1;
        }
    }
    
    void rec(string s)
    {
        int n = s.size();
        for(int gap = 0; gap < n; ++gap)
        {
            for(int j = 0; j+gap < n; ++j)
            {
                int x = j;
                int y = j+gap;
                
                if(x == y)
                {
                    dp[x][y] = true;
                    if(dp[x][y])
                        setSize(x, y);
                    continue;
                }
                if(y-x == 1)
                {
                    dp[x][y] = s[x] == s[y];
                    if(dp[x][y])
                        setSize(x, y);
                    continue;
                }
                dp[x][y] = dp[x+1][y-1] && s[x] == s[y];
                if(dp[x][y])
                    setSize(x, y);
            }
        }
    }
    
    string longestPalindrome(string s) 
    {
        memset(dp, false, sizeof(dp));
        rec(s);
        return s.substr(l, size);
    }
};
