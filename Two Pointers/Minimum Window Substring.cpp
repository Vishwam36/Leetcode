// By Vishwam Shriram Mundada
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/838/
// Decent

/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates)
is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

Constraints:
    m == s.length
    n == t.length
    1 <= m, n <= 105
    s and t consist of uppercase and lowercase English letters.
*/

class Solution {
public:
    string minWindow(string s, string t)
    {
        int n = s.size(), m = t.size();
        vector<int> ft(256, 0);
        for(auto& ch : t)
            ft[ch]++;
        
        vector<int> fs(256, 0), extra(256, 0);
        string ans;
        
        int l = 0, r = 0;
        while(r < n)
        {
            while(r < n && fs != ft)
            {
                int ch = s[r];
                if(ft[ch] > fs[ch])
                    fs[ch]++;
                else
                    extra[ch]++;
                
                r++;
            }
            
            bool f = 0;
            
            while(l < r && fs == ft)
            {
                int ch = s[l];
                if(extra[ch])
                    extra[ch]--;
                else
                {
                    fs[ch]--;
                    f = 1;
                }
                l++;
            }
            
            if(f && ans == "" || ans.size() > r-l+1)
                ans = s.substr(l-1, r-l+1);
        }
        
        return ans;
    }
};
