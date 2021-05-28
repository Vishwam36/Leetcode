// By Vishwam Shriram Mundada
// https://leetcode.com/problems/remove-invalid-parentheses/
// Good question
// REF : https://www.youtube.com/watch?v=k4LX7OSl2bY&ab_channel=happygirlzthappygirlzt

/*
Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return all the possible results. You may return the answer in any order.

Example 1:
Input: s = "()())()"
Output: ["(())()","()()()"]

Example 2:
Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]

Example 3:
Input: s = ")("
Output: [""]

Constraints:
1 <= s.length <= 25
s consists of lowercase English letters and parentheses '(' and ')'.
There will be at most 20 parentheses in s.
*/

class Solution {
public:
    set<string> ans;
    
    void helper(string s, int left, int right, vector<char> &par)
    {
        int count = 0;
        for(; right < s.size(); ++right)
        {
            if(s[right] == par[0])
                count++;
            else if(s[right] == par[1])
                count--;
            
            if(count < 0)
                break;
        }
        
        if(count < 0)
        {
            for(; left <= right; ++left)
                if(s[left] == par[1])
                    helper(s.substr(0, left) + s.substr(left+1), left, right, par);
        }
        else if(count > 0)
        {
            reverse(s.begin(), s.end());
            vector<char> revPar = {')', '('};
            helper(s, 0, 0, revPar);
        }
        else
        {
            if(par[0] == '(')
                ans.insert(s);
            else
            {
                reverse(s.begin(), s.end());
                ans.insert(s);
            }
        }
    }
    
    vector<string> removeInvalidParentheses(string s) 
    {
        vector<char> par = {'(', ')'};
        helper(s, 0, 0, par);
        return vector<string> (ans.begin(), ans.end());
    }
};
