// By Vishwam Shriram Mundada
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/113/math/815/
// Easy

/*
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

    Starting with any positive integer, replace the number by the sum of the squares of its digits.
    Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
    Those numbers for which this process ends in 1 are happy.

Return true if n is a happy number, and false if not.

Example 1:
Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

Example 2:
Input: n = 2
Output: false

Constraints:
    1 <= n <= 2^31 - 1
*/

class Solution {
public:
    bool isHappy(int n) 
    {
        set<int> vis;
        vis.insert(n);
        
        while(n != 1)
        {
            string s = to_string(n);
            n = 0;
            for(auto ch : s)
            {
                int d = ch-'0';
                n += d*d;
            }
            
            if(vis.find(n) != vis.end())
                break;
            
            vis.insert(n);
        }
        
        return n==1;
    }
};
