// By Vishwam Shriram Mundada
// https://leetcode.com/problems/word-break-ii/
// Easy

/*
Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. 
Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:
Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]

Example 2:
Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.

Example 3:
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: []

Constraints:
    1 <= s.length <= 20
    1 <= wordDict.length <= 1000
    1 <= wordDict[i].length <= 10
    s and wordDict[i] consist of only lowercase English letters.
    All the strings of wordDict are unique.
*/

class Solution {
public:
    vector<string> ans;
    
    void rec(int index, string s, vector<string>& wordDict, string temp)
    {
        if(index == s.size())
        {
            temp.pop_back(); // to remove extra space at end
            ans.push_back(temp);
            return;
        }
        
        string word;
        for(int i = index; i < s.size(); ++i)
        {
            word += s[i];
            if(find(wordDict.begin(), wordDict.end(), word) != wordDict.end())
            {
                rec(i+1, s, wordDict, temp+word+" ");
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        rec(0, s, wordDict, "");
        return ans;
    }
};
