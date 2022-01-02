// By Vishwam Shriram Mundada
// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
// Decent

/*
Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.

Example 1:
Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.

Example 2:
Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d] + 101[e] + 101[e] to the sum.
Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.

Constraints:
    1 <= s1.length, s2.length <= 1000
    s1 and s2 consist of lowercase English letters.
*/

// REF : https://www.youtube.com/watch?v=GPePWKCEy24

class Solution {
public:
    int n1, n2;
    vector<vector<int> > dp;
    
    int rec(int i, int j, string &s1, string &s2)
    {
        if(dp[i][j] != -1)
            return dp[i][j];
        if(i == n1 && j == n2)
            return dp[i][j] = 0;
        if(i == n1)
            return dp[i][j] = s2[j] + rec(i, j+1, s1, s2);
        if(j == n2)
            return dp[i][j] = s1[i] + rec(i+1, j, s1, s2);
        
        if(s1[i] == s2[j])
            return dp[i][j] = rec(i+1, j+1, s1, s2);
        
        return dp[i][j] = min(s1[i]+rec(i+1, j, s1, s2), s2[j]+rec(i, j+1, s1, s2));
    }
    
    int minimumDeleteSum(string s1, string s2) 
    {
        n1 = s1.size(), n2 = s2.size();
        dp = vector<vector<int> >(n1+1, vector<int>(n2+1, -1));
        return rec(0, 0, s1, s2);
    }
};
