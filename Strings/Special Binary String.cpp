// By Vishwam Shriram Mundada
// Special binary strings are binary strings with the following two properties:
// Decent question

/*
Special binary strings are binary strings with the following two properties:
    The number of 0's is equal to the number of 1's.
    Every prefix of the binary string has at least as many 1's as 0's.

You are given a special binary string s.

A move consists of choosing two consecutive, non-empty, special substrings of s, and swapping them. 
Two strings are consecutive if the last character of the first string is exactly one index before the first character of the second string.

Return the lexicographically largest resulting string possible after applying the mentioned operations on the string.

Example 1:
Input: s = "11011000"
Output: "11100100"
Explanation: The strings "10" [occuring at s[1]] and "1100" [at s[3]] are swapped.
This is the lexicographically largest string possible after some number of swaps.

Example 2:
Input: s = "10"
Output: "10"

Constraints:
    1 <= s.length <= 50
    s[i] is either '0' or '1'.
    s is a special binary string.
*/

class Solution {
public:
    bool isSpecial(string &s)
    {
        int o = 0, z = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '0')
                z++;
            else
                o++;
            
            if(o < z)
                return false;
        }
        return o == z;
    }
    
    string getSwapped(string &s, int idx, int l1, int l2) // l1 = len(left substr), l2 = len(right substr)
    {
        string ans;
        for(int i = 0; i <= idx-l1; ++i)
            ans.push_back(s[i]);
        for(int i = idx+1; i < idx+1+l2; ++i)
            ans.push_back(s[i]);
        for(int i = idx-l1+1; i <= idx; ++i)
            ans.push_back(s[i]);
        for(int i = idx+1+l2; i < s.size(); ++i)
            ans.push_back(s[i]);
        return ans;
    }
    
    string fun(string &s)
    {
        string ans = s, copy;
        
        for(int i = 0; i < s.size()-1; ++i)
        {
            for(int j = 1; j <= i+1; j++) // j is length of left substring
            {
                string s1 = s.substr(i-j+1, j);
                if(!isSpecial(s1))
                    continue;
                
                for(int k = 1; k <= s.size()-i-1; ++k) // k is length of right substring
                {
                    string s2 = s.substr(i+1, k);
                    if(!isSpecial(s2))
                        continue;
                    
                    copy = s;
                    ans = max(ans, getSwapped(copy, i, j, k));
                }
            }
        }
        return ans;
    }
    
    string makeLargestSpecial(string s) 
    {
        string ans = s, temp;
        while(1)
        {
            temp = fun(ans);
            if(ans == temp)
                break;
            ans = temp;
        }
        return ans;
    }
};
