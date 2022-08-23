// By Vishwam Shriram Mundada
// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/885/
// Rolling hash || KMP

/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:
What should we return when needle is an empty string? This is a great question to ask during an interview.
For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1

Example 3:
Input: haystack = "", needle = ""
Output: 0

Constraints:
    0 <= haystack.length, needle.length <= 5 * 10^4
    haystack and needle consist of only lower-case English characters.
*/

class Solution {
public:
    #define ll long long
    ll mod = 1e9 + 7;
    
    ll myPow(ll a, ll b)
    {
        if(b == 0)
            return 1;
        
        ll ans;
        if(b % 2 == 0)
        {
            ans = myPow(a, b/2);
            ans = ans * ans;
        }
        else
        {
            ans = myPow(a, b/2);
            ans = ((ans * ans) % mod) * a;
        }
        return ans % mod;
    }
    
    int strStr(string haystack, string needle)
    {
        ll n = haystack.size();
        ll k = needle.size();
        
        ll needle_hash = 0, hash = 0;
        
        for(int i = 0; i < k; ++i)
        {
            needle_hash += (myPow(26, k-i) * (needle[i]-'a')) % mod;
            hash += (myPow(26, k-i) * (haystack[i]-'a')) % mod;
        }
        
        if(hash % mod == needle_hash % mod)
            return 0;
        
        for(int i = k; i < n; ++i)
        {
            hash -= myPow(26, k) * (haystack[i-k] - 'a');
            hash = (hash + mod) % mod;
            
            hash *= 26;
            hash %= mod;
            
            hash += 26 * (haystack[i]-'a');
            hash %= mod;
            
            if(needle_hash % mod == hash % mod)
                return i-k+1;
        }
        return -1;
    }
};


// KMP Algo

class Solution {
public:
    int strStr(string text, string pat)
    {
        int nt = text.size(), np = pat.size();
        vector<int> p(np, 0);
        
        int i = 0, j = 1;
        while(j < np)
        {
            if(pat[i] == pat[j])
            {
                p[j] = i+1;
                ++i;
                ++j;
            }
            else
            {
                int x = j;
                while(i > 0)
                {
                    i = p[x-1];
                    x = i;
                    if(pat[i] == pat[j])
                    {
                        p[j] = i+1;
                        ++i;
                        ++j;
                        break;
                    }
                }
                if(i == 0)
                {
                    p[j] = 0;
                    j++;
                    i = 0;
                }
            }
        }
        
        j = 0;
        for(int i = 0 ; i < nt; ++i)
        {
            if(text[i] == pat[j])
            {
                if(j == np-1)
                    return i-np+1;
                
                j++;
            }
            else
            {
                while(j > 0)
                {
                    j = p[j-1];
                    if(pat[j] == text[i])
                    {
                        ++j;
                        break;
                    }
                }
                
                if(j == 0 && pat[j] == text[i])
                    ++j;
            }
        }
        
        return -1;
    }
};
