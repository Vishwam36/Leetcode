// By Vishwam Shriram Mundada
// https://leetcode.com/problems/construct-string-with-repeat-limit/
// Easy

/*
You are given a string s and an integer repeatLimit. Construct a new string repeatLimitedString using the characters of s such that no letter appears 
more than repeatLimit times in a row. You do not have to use all characters from s.

Return the lexicographically largest repeatLimitedString possible.

A string a is lexicographically larger than a string b if in the first position where a and b differ, string a has a letter that appears later in the alphabet 
than the corresponding letter in b. If the first min(a.length, b.length) characters do not differ, then the longer string is the lexicographically larger one.

Example 1:

Input: s = "cczazcc", repeatLimit = 3
Output: "zzcccac"
Explanation: We use all of the characters from s to construct the repeatLimitedString "zzcccac".
The letter 'a' appears at most 1 time in a row.
The letter 'c' appears at most 3 times in a row.
The letter 'z' appears at most 2 times in a row.
Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
The string is the lexicographically largest repeatLimitedString possible so we return "zzcccac".
Note that the string "zzcccca" is lexicographically larger but the letter 'c' appears more than 3 times in a row, so it is not a valid repeatLimitedString.

Example 2:

Input: s = "aababab", repeatLimit = 2
Output: "bbabaa"
Explanation: We use only some of the characters from s to construct the repeatLimitedString "bbabaa". 
The letter 'a' appears at most 2 times in a row.
The letter 'b' appears at most 2 times in a row.
Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
The string is the lexicographically largest repeatLimitedString possible so we return "bbabaa".
Note that the string "bbabaaa" is lexicographically larger but the letter 'a' appears more than 2 times in a row, so it is not a valid repeatLimitedString.

Constraints:
    1 <= repeatLimit <= s.length <= 10^5
    s consists of lowercase English letters.
*/

class Solution {
public:
    string repeatLimitedString(string s, int limit) 
    {
        int n = s.size();
        priority_queue<pair<int, int> > pq;
        vector<int> f(26, 0);
        for(auto ch : s)
            f[ch-'a']++;
        
        for(int i = 0; i < 26; ++i)
            if(f[i])
                pq.push({i, f[i]});
        
        string ans;
        char last = '0';
        int freq = 0;
        while(!pq.empty())
        {
            auto p = pq.top(); pq.pop();
            char curr = 'a'+p.first;
            int currf = p.second;
            
            if(last == curr)
            {
                if(freq == limit)
                {
                    if(pq.size() == 0)
                        return ans;
                    
                    auto q = pq.top(); pq.pop();
                    
                    ans.push_back('a'+q.first);
                    q.second--;
                    
                    if(q.second)
                        pq.push(q);
                    
                    pq.push(p);
                    
                    last = 'a'+q.first;
                    freq = 1;
                    
                    continue;
                }
                else
                {
                    freq++;
                }
            }
            else
            {
                last = curr;
                freq = 1;
            }
            
            ans.push_back(curr);
            currf--;
            
            if(currf)
                pq.push({curr-'a', currf});
        }
        
        return ans;
    }
};
