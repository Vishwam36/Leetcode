// By Vishwam Shriram Mundada
// https://leetcode.com/problems/generate-parentheses/
// Easy
/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
*/

class Solution {
public:
    void rec(int n, int open, int close, string temp, vector<string> &ans)
    {
        if(open > n)
            return;
        
        if(close == n && open == close)
        {
            ans.push_back(temp);
            return;
        }
        
        if(open == close)
        {
            temp.push_back('(');
            rec(n, open+1, close, temp, ans);
        }
        if(open > close && open <= n)
        {
            temp.push_back('(');
            rec(n, open+1, close, temp, ans);
            temp.pop_back();
            
            temp.push_back(')');
            rec(n, open, close+1, temp, ans);
            temp.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;
        ans.clear();
        rec(n, 0, 0, "", ans);
        return ans;
    }
};
