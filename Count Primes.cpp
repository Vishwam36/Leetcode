// By Vishwam Shriram Mundada
// https://leetcode.com/explore/interview/card/top-interview-questions-easy/102/math/744/
// Sieve of Eratosthenes

/*
Given an integer n, return the number of prime numbers that are strictly less than n.

Example 1:
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Example 2:
Input: n = 0
Output: 0

Example 3:
Input: n = 1
Output: 0

Constraints:
    0 <= n <= 5 * 10^6
*/

bool done = 0;
vector<int> f;

class Solution {
public:
    void init()
    {
        f = vector<int>(5000005, 1);
        f[0] = 0;
        f[1] = 0;
        
        for(int i = 2; i*i < f.size(); ++i)
            if(f[i])
                for(int j = i*i; j < f.size(); j+=i)
                    f[j] = 0;
        
        for(int i = 2; i < f.size(); ++i)
            f[i] += f[i-1];
    }
    
    int countPrimes(int n)
    {
        if(n == 0)
            return 0;
        
        if(done == 0)
        {
            init();
            done = 1;
        }
        
        return f[n-1];
    }
};
