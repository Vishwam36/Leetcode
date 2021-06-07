// By Vishwam Shriram Mundada
// https://leetcode.com/problems/word-ladder/
// Good question

/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, 
or 0 if no such sequence exists.

Example 1:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

Example 2:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.

Constraints:
1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
*/

class Solution {
public:
    map<string, unordered_set<string> > m;
    
    int bfs(string begin, string end)
    {
        unordered_set<string> vis;
        vis.insert(begin);
        
        queue<string> q;
        q.push(begin);
        int ans = 1;
        
        while(!q.empty())
        {
            int len = q.size();
            while(len--)
            {
                string curr = q.front(); q.pop();
                
                if(curr == end)
                    return ans;
            
                for(auto it = m[curr].begin(); it != m[curr].end(); ++it)
                {
                    string next = *it;
                    if(vis.find(next) == vis.end())
                    {
                        q.push(next);
                        vis.insert(next);
                    }
                }
            }
            ans++;
        }
        return 0;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        wordList.push_back(beginWord);
        unordered_set<string> list;
        for(auto s : wordList)
            list.insert(s);
        
        for(auto s : wordList)
        {
            for(int i = 0; i < s.size(); ++i)
            {
                string copy = s;
                for(char ch = 'a'; ch <= 'z'; ++ch)
                {
                    if(ch == s[i])
                        continue;
                    
                    copy[i] = ch;
                    if(list.find(copy) != list.end())
                    {
                        m[s].insert(copy);
                        m[copy].insert(s);
                    }
                }
            }
        }
        return bfs(beginWord, endWord);
    }
};
