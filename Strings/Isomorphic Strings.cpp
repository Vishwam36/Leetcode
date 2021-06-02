// By Vishwam Shriram Mundada
// https://leetcode.com/problems/isomorphic-strings/
// Easy

/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

Example 1:
Input: s = "egg", t = "add"
Output: true

Example 2:
Input: s = "foo", t = "bar"
Output: false

Example 3:
Input: s = "paper", t = "title"
Output: true

Constraints:
    1 <= s.length <= 5 * 104
    t.length == s.length
    s and t consist of any valid ascii character.
*/

// Hint : We have to check one to one mapping of characters

class Solution {
public:
    bool isIsomorphic(string str1, string str2) 
    {
        int n1 = str1.size(), n2 = str2.size();
        if(n1 != n2)
            return false;
        
        int m[256], f1[256], f2[256];
        for(int i = 0; i < 256; ++i)
        {
            m[i] = -1;
            f1[i] = 0;
            f2[i] = 0;
        }
        
        for(int i = 0; i < n1; ++i)
        {
            int ch1 = str1[i];
            int ch2 = str2[i];
            
            f1[ch1]++;
            f2[ch2]++;
            
            if(m[ch1] == -1)
                m[ch1] = ch2;
            
            else if(m[ch1] != ch2)
                return false;
        }
        
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < 256; ++i)
        {
            if(f1[i] > 0)
                cnt1++;
            if(f2[i] > 0)
                cnt2++;
        }
        
        if(cnt1 != cnt2)
            return false;
        return true;
    }
};
