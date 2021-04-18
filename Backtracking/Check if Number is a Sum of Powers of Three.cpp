// By Vishwam Shriram Mundada
// https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/
// Easy, not a backtracking problem
/*
Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three. Otherwise, return false.
*/

class Solution {
public:
    int power = 16;
    
    bool checkPowersOfThree(int n) 
    {
        if(n == 0)
            return 1;
        
        for(int i = power-1; i >= 0; --i)
        {
            if(pow(3, i) <= n)
            {
                power = i;
                return checkPowersOfThree(n - pow(3, i));
            }
        }
        return 0;
    }
};
