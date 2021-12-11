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
    vector<string> ans;
    
    void rec(int open, int close, string &temp)
    {
        if(open == 0 && close == 0)
            ans.push_back(temp);
                
        if(open)
        {
            temp.push_back('(');
            rec(open-1, close, temp);
            temp.pop_back();
        }
        if(close && open < close)
        {
            temp.push_back(')');
            rec(open, close-1, temp);
            temp.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) 
    {
        string temp;
        rec(n, n, temp);
        return ans;
    }
};
