// By Vishwam Shriram Mundada
// https://leetcode.com/problems/longest-happy-prefix/
// KMP algo

/*
A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).

Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.

Example 1:
Input: s = "level"
Output: "l"
Explanation: s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), and suffix ("l", "el", "vel", "evel"). The largest prefix which is also suffix 
is given by "l".

Example 2:
Input: s = "ababab"
Output: "abab"
Explanation: "abab" is the largest prefix which is also suffix. They can overlap in the original string.

Example 3:
Input: s = "leetcodeleet"
Output: "leet"

Example 4:
Input: s = "a"
Output: ""

Constraints:
    1 <= s.length <= 105
    s contains only lowercase English letters.
*/

class Solution {
public:
    string longestPrefix(string s) 
    {
        vector<int> pi(s.size(), 0);
        for(int i = 1; i < s.size(); ++i)
        {
            int j = pi[i-1];
            
            while(j > 0 && s[j] != s[i])
                j = pi[j-1];
            
            if(s[i] == s[j])
                j++;
            
            pi[i] = j;
        }
        return s.substr(0, pi.back());
    }
};
