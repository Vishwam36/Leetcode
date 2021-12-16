// By Vishwam Shriram Mundada
// https://leetcode.com/problems/24-game/
// Good

/*
You are given an integer array cards of length 4. You have four cards, each containing a number in the range [1, 9]. You should arrange the numbers on these cards
in a mathematical expression using the operators ['+', '-', '*', '/'] and the parentheses '(' and ')' to get the value 24.

You are restricted with the following rules:

    The division operator '/' represents real division, not integer division.
        For example, 4 / (1 - 2 / 3) = 4 / (1 / 3) = 12.
    Every operation done is between two numbers. In particular, we cannot use '-' as a unary operator.
        For example, if cards = [1, 1, 1, 1], the expression "-1 - 1 - 1 - 1" is not allowed.
    You cannot concatenate numbers together
        For example, if cards = [1, 2, 1, 2], the expression "12 + 12" is not valid.

Return true if you can get such expression that evaluates to 24, and false otherwise.

Example 1:
Input: cards = [4,1,8,7]
Output: true
Explanation: (8-4) * (7-1) = 24

Example 2:
Input: cards = [1,2,1,2]
Output: false

Constraints:
    cards.length == 4
    1 <= cards[i] <= 9
*/

class Solution {
public:
    double eps = 0.001;
    
    bool valid(vector<int> &nums)
    {
        double a = nums[0], b = nums[1], c = nums[2], d = nums[3];
        
        return valid(a+b, c, d) || valid(a-b, c, d) || valid(a*b, c, d) || valid(a/b, c, d)
            || valid(a, b+c, d) || valid(a, b-c, d) || valid(a, b*c, d) || valid(a, b/c, d)
            || valid(a, b, c+d) || valid(a, b, c-d) || valid(a, b, c*d) || valid(a, b, c/d);
    }
    
    bool valid(double a, double b, double c)
    {
        return valid(a+b, c) || valid(a-b, c) || valid(a*b, c) || valid(a/b, c)
            || valid(a, b+c) || valid(a, b-c) || valid(a, b*c) || valid(a, b/c);
    }
    
    bool valid(double a, double b)
    {
        return abs(a+b-24.0) < eps || abs(a-b-24.0) < eps || abs(a*b-24.0) < eps || abs(a/b-24.0) < eps;
    }
    
    bool judgePoint24(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        
        do{
            if(valid(nums))
                return true;
        }while(next_permutation(nums.begin(), nums.end()));
        
        return false;
    }
};
