// By Vishwam Shriram Mundada
// https://leetcode.com/problems/find-substring-with-given-hash-value/
// Good

/*
The hash of a 0-indexed string s of length k, given integers p and m, is computed using the following function:

    hash(s, p, m) = (val(s[0]) * p0 + val(s[1]) * p1 + ... + val(s[k-1]) * pk-1) mod m.

Where val(s[i]) represents the index of s[i] in the alphabet from val('a') = 1 to val('z') = 26.

You are given a string s and the integers power, modulo, k, and hashValue. Return sub, the first substring of s of length k such that hash(sub, power, modulo) == hashValue.

The test cases will be generated such that an answer always exists.

A substring is a contiguous non-empty sequence of characters within a string.

Example 1:

Input: s = "leetcode", power = 7, modulo = 20, k = 2, hashValue = 0
Output: "ee"
Explanation: The hash of "ee" can be computed to be hash("ee", 7, 20) = (5 * 1 + 5 * 7) mod 20 = 40 mod 20 = 0. 
"ee" is the first substring of length 2 with hashValue 0. Hence, we return "ee".

Example 2:

Input: s = "fbxzaad", power = 31, modulo = 100, k = 3, hashValue = 32
Output: "fbx"
Explanation: The hash of "fbx" can be computed to be hash("fbx", 31, 100) = (6 * 1 + 2 * 31 + 24 * 312) mod 100 = 23132 mod 100 = 32. 
The hash of "bxz" can be computed to be hash("bxz", 31, 100) = (2 * 1 + 24 * 31 + 26 * 312) mod 100 = 25732 mod 100 = 32. 
"fbx" is the first substring of length 3 with hashValue 32. Hence, we return "fbx".
Note that "bxz" also has a hash of 32 but it appears later than "fbx".

Constraints:
    1 <= k <= s.length <= 2 * 10^4
    1 <= power, modulo <= 10^9
    0 <= hashValue < modulo
    s consists of lowercase English letters only.
    The test cases are generated such that an answer always exists.
*/

class Solution {
public:
    #define ll long long
    ll mod;
        
    ll myPow(ll a, ll p)
    {
        if(p == 0)
            return 1;
        
        ll ans;
        if(p % 2 == 0)
        {
            ans = myPow(a, p/2);
            ans = (ans * ans) % mod;
        }
        else
        {
            ans = myPow(a, p/2);
            ans = (((ans * ans) % mod) * a) % mod;
        }
        
        return ans;
    }
    
    ll val(char ch)
    {
        return ch-'a'+1;
    }
    
    string subStrHash(string s, int prime, int modulo, int k, int hashValue)
    {
        mod = modulo;
        ll n = s.size(), size = k-1, temp = 0, idx = 0, hash = hashValue, p = prime;
        
        for(ll i = n-1; i >= n-k; --i)
        {
            temp += val(s[i]) * myPow(p, size--);
            temp = temp % mod;
        }
        
        if(temp == hash)
            idx = n-k;
        
        for(int i = n-k-1; i >= 0; --i)
        {
            ll pre = val(s[i+k]);
            temp -= pre * myPow(p, k-1);
            
            while(temp < 0)
                temp = (temp + mod) % mod;
            
            temp = (temp * p) % mod;
            
            temp += val(s[i]);
            temp = temp % mod;
            
            if(temp == hash)
                idx = i;            
        }
        
        return s.substr(idx, k);
    }
};
