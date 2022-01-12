// By Vishwam Shriram Mundada
// https://leetcode.com/problems/longest-word-in-dictionary/
// Decent

/*
Given an array of strings words representing an English Dictionary, return the longest word in words that can be built one character at a time by other words in words.

If there is more than one possible answer, return the longest word with the smallest lexicographical order. If there is no answer, return the empty string.

Example 1:
Input: words = ["w","wo","wor","worl","world"]
Output: "world"
Explanation: The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".

Example 2:
Input: words = ["a","banana","app","appl","ap","apply","apple"]
Output: "apple"
Explanation: Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".

Constraints:
    1 <= words.length <= 1000
    1 <= words[i].length <= 30
    words[i] consists of lowercase English letters.
*/

class Solution {
public:
    string longestWord(vector<string>& words)
    {
        sort(words.begin(), words.end());
        unordered_set<string> vis;
        string ans;
        
        for(auto& s : words)
        {
            if(s.size() == 1)
                vis.insert(s);
            
            else
            {
                string temp = s;
                temp.pop_back();
                if(vis.find(temp) != vis.end())
                    vis.insert(s);
            }
        }
        
        for(auto s : vis)
        {
            if(ans.size() < s.size())
                ans = s;
            else if(ans.size() == s.size())
                ans = min(ans, s);
        }
        
        return ans;
    }
};