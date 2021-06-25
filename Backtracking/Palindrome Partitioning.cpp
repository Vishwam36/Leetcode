// By Vishwam Shriram Mundada
// https://leetcode.com/problems/palindrome-partitioning/
// Easy

/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:
Input: s = "a"
Output: [["a"]]

Constraints:
1 <= s.length <= 16
s contains only lowercase English letters.
*/

class Solution {
public:
    vector<vector<string> > ans;
    
    bool isPali(int l, int r, string &s)
    {
        while(l < r)
            if(s[l++] != s[r--])
                return false;
        
        return true;
    }
    
    void rec(int l, string &s, vector<string>& temp)
    {
        if(l == s.size())
        {
            ans.push_back(temp);
            return;
        }
        
        for(int i = l; i < s.size(); ++i)
        {
            if(isPali(l, i, s))
            {
                temp.push_back(s.substr(l, i-l+1));
                rec(i+1, s, temp);
                temp.pop_back();    
            }           
        }
    }
    
    vector<vector<string>> partition(string s) 
    {
        vector<string> temp;
        rec(0, s, temp);
        return ans;
    }
};
