// By Vishwam Shriram Mundada
// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/887/
// Easy

/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Constraints:
    1 <= strs.length <= 200
    0 <= strs[i].length <= 200
    strs[i] consists of only lower-case English letters.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        int minSize = INT_MAX;
        for(auto& s : strs)
            minSize = min(minSize, (int)s.size());
        
        string ans;
        for(int size = 1; size <= minSize; ++size)
        {
            bool f = 1;
            string match = strs[0].substr(0, size);
            for(auto s : strs)
            {
                if(match != s.substr(0, size))
                {
                    f = 0;
                    break;
                }
            }
            if(f)
                ans = match;
        }
        return ans;
    }
};
