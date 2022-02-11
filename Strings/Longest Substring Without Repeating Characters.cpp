// By Vishwam Shriram Mundada
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/779/
// Easy

/*
Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Constraints:
    0 <= s.length <= 5 * 10^4
    s consists of English letters, digits, symbols and spaces.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size(), l = 0, r = 0, ans = 0;
        vector<int> f(256, 0);
        
        while(r < n)
        {
            while(r < n)
            {
                f[s[r]]++;
                if(f[s[r]] > 1)
                    break;
                r++;
            }
            
            ans = max(ans, r-l);
            
            while(l < r && f[s[r]] > 1)
                f[s[l++]]--;
            
            ++r;
        }
        
        return ans;
    }
};
