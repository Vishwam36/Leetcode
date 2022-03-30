// By Vishwam Shriram Mundada
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/836/
// Decent

/*
Given a string s which represents an expression, evaluate this expression and return its value. 
The integer division should truncate toward zero.
You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

Example 1:
Input: s = "3+2*2"
Output: 7

Example 2:
Input: s = " 3/2 "
Output: 1

Example 3:
Input: s = " 3+5 / 2 "
Output: 5

Constraints:
    1 <= s.length <= 3 * 10^5
    s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
    s represents a valid expression.
    All the integers in the expression are non-negative integers in the range [0, 2^31 - 1].
    The answer is guaranteed to fit in a 32-bit integer.
*/

class Solution {
public:
    int calculate(string s)
    {
        deque<string> dq;
        int i = 0, n = s.size();
        while(i < n)
        {
            if(s[i] == ' ')
            {
                i++;
                continue;
            }
            
            if(!dq.empty() && (dq.back() == "*" || dq.back() == "/"))
            {
                string num;
                while(i < n && s[i] >= '0' && s[i] <= '9')
                    num.push_back(s[i++]);
                
                string op = dq.back(); dq.pop_back();
                int a = stoi(dq.back()); dq.pop_back();
                int b = stoi(num);
                
                if(op == "*")
                    dq.push_back(to_string(a*b));
                else
                    dq.push_back(to_string(a/b));
            }
            else
            {
                if(s[i] >= '0' && s[i] <= '9')
                {
                    string num;
                    while(i < n && s[i] >= '0' && s[i] <= '9')
                        num.push_back(s[i++]);
                    
                    dq.push_back(num);
                }
                else
                {
                    dq.push_back(string({s[i]}));
                    ++i;
                }
            }
        }
        
        while(dq.size() > 1)
        {
            int a = stoi(dq.front()); dq.pop_front();
            string op = dq.front(); dq.pop_front();
            int b = stoi(dq.front()); dq.pop_front();
            
            if(op == "+")
                dq.push_front(to_string(a+b));
            else
                dq.push_front(to_string(a-b));
        }
        
        return stoi(dq.front());
    }
};
