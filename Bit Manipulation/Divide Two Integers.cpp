// By Vishwam Shriram Mundada
// https://leetcode.com/problems/divide-two-integers/
// Good
// REF : https://www.youtube.com/watch?v=bdxJHWIyyqI

/*
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−2^31, 2^31 − 1]. For this problem, 
assume that your function returns 2^31 − 1 when the division result overflows.

Example 1:
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = truncate(3.33333..) = 3.

Example 2:
Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = truncate(-2.33333..) = -2.

Example 3:
Input: dividend = 0, divisor = 1
Output: 0

Example 4:
Input: dividend = 1, divisor = 1
Output: 1

Constraints:
    -2^31 <= dividend, divisor <= 2^31 - 1
    divisor != 0
*/

// Idea is to get quotient in the form of powers of 2
// Ex. 43/8 = 5 => 8*5 = 43 => 8*(2^2+2^0) = 43

class Solution {
public:
    int divide(int dividend, int divisor) 
    {
        int sign = (long long)dividend * divisor > 0 ? 1 : -1;
        
        long long divid = abs(dividend);
        long long divis = abs(divisor);
        
        long long q = 0; // quotient
        for(long long i = 31; i >= 0; --i)
        {
            if((divis << i) <= divid)
            {                
                divid -= (divis << i);
                q += ((long long)1 << i);
            }
        }
        return q * sign > INT_MAX || q * sign < INT_MIN ? INT_MAX : q * sign; // checking out of bounds
    }
};
