// By Vishwam Shriram Mundada
// https://leetcode.com/problems/minimum-cost-to-change-the-final-value-of-expression/
// Good question
// REF : // https://www.youtube.com/watch?v=DTuw-qEbco8

/*
Given a valid boolean expression as a string expression consisting of the characters '1','0','&' (bitwise AND operator),'|' (bitwise OR operator),'(', and ')'.

    For example, "()1|1" and "(1)&()" are not valid while "1", "(((1))|(0))", and "1|(0&(1))" are valid expressions.

Return the minimum cost to change the final value of the expression.

Example, if expression = "1|1|(0&0)&1", its value is 1|1|(0&0)&1 = 1|1|0&1 = 1|0&1 = 1&1 = 1. We want to apply operations so that the new expression evaluates to 0.

The cost of changing the final value of an expression is the number of operations performed on the expression. The types of operations are described as follows:

    Turn a '1' into a '0'.
    Turn a '0' into a '1'.
    Turn a '&' into a '|'.
    Turn a '|' into a '&'.

Note: '&' does not take precedence over '|' in the order of calculation. Evaluate parentheses first, then in left-to-right order.

Example 1:
Input: expression = "1&(0|1)"
Output: 1
Explanation: We can turn "1&(0|1)" into "1&(0&1)" by changing the '|' to a '&' using 1 operation.
The new expression evaluates to 0. 

Example 2:
Input: expression = "(0&0)&(0&0&0)"
Output: 3
Explanation: We can turn "(0&0)&(0&0&0)" into "(0|1)|(0&0&0)" using 3 operations.
The new expression evaluates to 1.

Example 3:
Input: expression = "(0|(1|0&1))"
Output: 1
Explanation: We can turn "(0|(1|0&1))" into "(0|(0|0&1))" using 1 operation.
The new expression evaluates to 0.

Constraints:
    1 <= expression.length <= 105
    expression only contains '1','0','&','|','(', and ')'
    All parentheses are properly matched.
    There will be no empty parentheses (i.e: "()" is not a substring of expression).
*/

class Solution {
public:
    unordered_map<int, int> leftMatch; // key is ')' index and value is matching '(' index
    
    void init(string expr)
    {
        stack<int> s;
        for(int i = expr.size()-1; i >= 0; --i)
        {
            if(expr[i] == ')')
                s.push(i);
            
            else if(expr[i] == '(')
            {
                leftMatch[s.top()] = i;
                s.pop();
            }
        }
    }
    
    // first value is result of expression from st to end
    // second value is minimum cost to change it
    pair<int, int> rec(int st, int end, string &expr)
    {
        if(st == end)
            return {expr[st] == '1', 1};
        
        int lm = end;
        if(expr[end] == ')')
            lm = leftMatch[end];
        
        if(lm == st)
            return rec(st+1, end-1, expr);
        
        auto p1 = rec(st, lm-2, expr);
        auto p2 = rec(lm, end, expr);
        
        int leftVal = p1.first;
        int leftCost = p1.second;
        int rightVal = p2.first;
        int rightCost = p2.second;
        
        char op = expr[lm-1];
        
        if(op == '&')
        {
            if(leftVal == 0 && rightVal == 0)
                return {0, min(1+leftCost, 1+rightCost) };
            if(leftVal == 1 && rightVal == 1)
                return {1, min(leftCost, rightCost) };
            else
                return {0, 1};
        }
        else
        {
            if(leftVal == 0 && rightVal == 0)
                return {0, min(leftCost, rightCost) };
            if(leftVal == 1 && rightVal == 1)
                return {1, min(1+leftCost, 1+rightCost) };
            else
                return {1, 1};
        }
    }
    
    int minOperationsToFlip(string expr) 
    {
        init(expr);
        return rec(0, expr.size()-1, expr).second;
    }
};
