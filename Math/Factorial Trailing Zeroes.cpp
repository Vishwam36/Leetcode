// By Vishwam Shriram Mundada
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/113/math/816/
// Easy

/*
Given an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.

Example 1:
Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.

Example 2:
Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.

Example 3:
Input: n = 0
Output: 0

Constraints:
    0 <= n <= 10^4
*/

class Solution {
public:
    int trailingZeroes(int n) 
    {
        int factors = 0;
        int num = 5;
        while(num <= n)
        {
            factors += n / num;
            num *= 5;
        }
        return factors;
    }
};
