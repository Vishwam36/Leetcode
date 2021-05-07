// By Vishwam Shriram Mundada
// https://leetcode.com/problems/minimum-number-of-operations-to-make-string-sorted/
// Good question and new concept of inverse factorial
// Ref : https://www.youtube.com/watch?v=Lfiz6iwp4l8&t=1644s&ab_channel=HappyCoding

/*
You are given a string s (0-indexed You are asked to perform the following operation on s until you get a sorted string:

Find the largest index i such that 1 <= i < s.length and s[i] < s[i - 1].
Find the largest index j such that i <= j < s.length and s[k] < s[i - 1] for all the possible values of k in the range [i, j] inclusive.
Swap the two characters at indices i - 1 and j
Reverse the suffix starting at index i.
Return the number of operations needed to make the string sorted. Since the answer can be too large, return it modulo 109 + 7.

Example 1:
Input: s = "cba"
Output: 5
Explanation: The simulation goes as follows:
Operation 1: i=2, j=2. Swap s[1] and s[2] to get s="cab", then reverse the suffix starting at 2. Now, s="cab".
Operation 2: i=1, j=2. Swap s[0] and s[2] to get s="bac", then reverse the suffix starting at 1. Now, s="bca".
Operation 3: i=2, j=2. Swap s[1] and s[2] to get s="bac", then reverse the suffix starting at 2. Now, s="bac".
Operation 4: i=1, j=1. Swap s[0] and s[1] to get s="abc", then reverse the suffix starting at 1. Now, s="acb".
Operation 5: i=2, j=2. Swap s[1] and s[2] to get s="abc", then reverse the suffix starting at 2. Now, s="abc".

Example 2:
Input: s = "aabaa"
Output: 2
Explanation: The simulation goes as follows:
Operation 1: i=3, j=4. Swap s[2] and s[4] to get s="aaaab", then reverse the substring starting at 3. Now, s="aaaba".
Operation 2: i=4, j=4. Swap s[3] and s[4] to get s="aaaab", then reverse the substring starting at 4. Now, s="aaaab".

Example 3:
Input: s = "cdbea"
Output: 63

Example 4:
Input: s = "leetcodeleetcodeleetcode"
Output: 982157772

Constraints:
1 <= s.length <= 3000
s consists only of lowercase English letters.
*/

typedef long long ll;
const int MOD = 1000000007;

class Solution {
public:
    ll myPow(int base, int power)
    {
        ll ans;
        if(power == 0)
            return 1;
        
        else if(power == 1)
            return base;
        
        if(power % 2 == 0)
        {
            ans = myPow(base, power/2);
            ans = ans * ans;
            ans %= MOD;
        }
        else if(power % 2 == 1)
        {
            ans = myPow(base, power/2);
            ans = ((base * ans) % MOD) * ans;
            ans %= MOD;
        }
        return ans;
    }
    
    int makeStringSorted(string s) 
    {
        ll ans = 0;
        int n = s.size();
        ll fact[n+1];
        ll invFact[n+1];
        fact[0] = 1;
        invFact[0] = 1;
        
        for(int i = 1; i <= n; ++i)
        {
            fact[i] = (fact[i-1] * i) % MOD;
            invFact[i] = myPow(fact[i], MOD-2);
        }
        
        for(int i = 0; i < n; ++i)
        {
            int f[26]; // frequency array
            for(int j = 0; j < 26; ++j)
                f[j] = 0;
            
            f[s[i] - 'a']++;
            for(int j = i+1; j < n; ++j)
                f[s[j] - 'a']++;
            
            set<char> taken;
            for(int j = i+1; j < n; ++j)
            {
                // if there is letter on right which is smaller than current and which is not swapped earlier
                if(s[j] < s[i] && taken.find(s[j]) == taken.end())
                {
                    taken.insert(s[j]);
                    f[s[j] - 'a']--; // swap step
                    
                    ll cnt = fact[n-i-1]; // total possible combination if there are no duplicates
                    for(int k = 0; k < 26; ++k)
                    {
                        cnt *= invFact[f[k]]; // take care of duplicates
                        cnt %= MOD;
                    }
                    ans += cnt;
                    ans %= MOD;
                    
                    f[s[j] - 'a']++; // swap back step
                }
            }
        }
        return ans;
    }
};
