// By Vishwam Shriram Mundada
// https://leetcode.com/problems/monotone-increasing-digits/
// Decent

/*
An integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.

Given an integer n, return the largest number that is less than or equal to n with monotone increasing digits.

Example 1:
Input: n = 10
Output: 9

Example 2:
Input: n = 1234
Output: 1234

Example 3:
Input: n = 332
Output: 299

Constraints:
    0 <= n <= 10^9
*/


// REF : https://www.youtube.com/watch?v=LuBbYBnCNpk&t=246s

class Solution {
public:
    void fun(string &s, int i)
    {
        s[i]--;
        int j = i+1;
        while(j < s.size())
            s[j++] = '9';
    }
    
    int monotoneIncreasingDigits(int n)
    {
        string s = to_string(n);
        
        int i = 0;
        while(i < s.size()-1 && s[i] <= s[i+1])
            ++i;
        
        while(i >= 0)
        {
            if(i+1 < s.size() && s[i] > s[i+1])
                fun(s, i);
            i--;
        }
        
        return stoi(s);
    }
};
