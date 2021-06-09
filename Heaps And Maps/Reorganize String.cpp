// By Vishwam Shriram Mundada
// https://leetcode.com/problems/reorganize-string/
// Decent

/*
Given a string s, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:
Input: s = "aab"
Output: "aba"

Example 2:
Input: s = "aaab"
Output: ""

Note:
    s will consist of lowercase letters and have length in range [1, 500].
*/

class Solution {
public:
    string reorganizeString(string s) 
    {
        unordered_map<char, int> m;
        for(auto ch : s)
            m[ch]++;
        
        string ans;
        priority_queue<pair<int, char> > pq;
        for(auto it = m.begin(); it != m.end(); ++it)
            pq.push({it->second, it->first});
        
        while(!pq.empty())
        {
            if(pq.size() == 1)
            {
                auto [fa, a] = pq.top(); pq.pop();
                if(fa > 1)
                    return "";
                ans.push_back(a);
                return ans;
            }
            
            auto [fa, a] = pq.top(); pq.pop();
            auto [fb, b] = pq.top(); pq.pop();
            
            ans.push_back(a);
            ans.push_back(b);
            fa--;
            fb--;
            
            if(fa > 0)
                pq.push({fa, a});
            if(fb > 0)
                pq.push({fb, b});
        }
        
        return ans;
    }
};
