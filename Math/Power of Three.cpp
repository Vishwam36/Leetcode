// By Vishwam Shriram Mundada
// https://leetcode.com/problems/power-of-three/
// Easy

/*
Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.

Example 1:
Input: n = 27
Output: true

Example 2:
Input: n = 0
Output: false

Example 3:
Input: n = 9
Output: true

Constraints:
    -2^31 <= n <= 2^31 - 1
*/

// App 1 : 
class Solution {
public:
    bool isPowerOfThree(int n) 
    {
        return n > 0 && (int)pow(3,19) % n == 0; // 3^20 > INT_MAX
    }
};

// App 2 : 
class Solution {
public:
    bool isPowerOfThree(int n) 
    {
        if(n > 0)
            return ceil(log10(n)/log10(3)) == floor(log10(n)/log10(3));
        return false;
    }
};

// App 3 : 
// Iterative / Recursive
