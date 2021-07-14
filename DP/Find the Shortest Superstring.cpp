// By Vishwam Shriram Mundada
// https://leetcode.com/problems/find-the-shortest-superstring/
// Good question, DP + Bit Masking

/*
Given an array of strings words, return the smallest string that contains each string in words as a substring. If there are multiple valid strings of the 
smallest length, return any of them.

You may assume that no string in words is a substring of another string in words.

Example 1:
Input: words = ["alex","loves","leetcode"]
Output: "alexlovesleetcode"
Explanation: All permutations of "alex","loves","leetcode" would also be accepted.

Example 2:
Input: words = ["catg","ctaagt","gcta","ttca","atgcatc"]
Output: "gctaagttcatgcatc"

Constraints:
    1 <= words.length <= 12
    1 <= words[i].length <= 20
    words[i] consists of lowercase English letters.
    All the strings of words are unique.
*/

// REF : https://www.youtube.com/watch?v=b1HcnDfLzFw&ab_channel=HappyCoding

class Solution {
public:
    // cost to append w1->w2
    int getCost(string &w1, string &w2)
    {
        int n1 = w1.size(), n2 = w2.size();
        
        int matchLen = 0;
        for(int i = 1; i < min(w1.size(), w2.size()); ++i)
            if(w2.substr(0, i) == w1.substr(w1.size()-i))
                matchLen = i;
        
        return w2.size()-matchLen;
    }
    
    string shortestSuperstring(vector<string>& words) 
    {
        int n = words.size();
        vector<vector<int> > cost(n, vector<int>(n));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(i != j)
                    cost[i][j] = getCost(words[i], words[j]);
        
        string ans;
        int end = (1 << n) - 1; // 1111111 shows all chosen
        int preMask, minCost = INT_MAX;
        vector<vector<pair<int, string> > > dp(end+1, vector<pair<int, string> >(n+1, {INT_MAX, ""}));
        
        for(int mask = 1; mask <= end; ++mask)
        {
            for(int set = 0; set < n; ++set)
            {
                if(((mask) & (1 << set)) == 0) // this word is not used yet
                    continue;
                
                preMask = ((mask) ^ (1 << set));
                
                if(preMask == 0) // shows set th is the first word
                {
                    dp[mask][set] = {words[set].size(), words[set]};
                }
                else
                {
                    // check all possible ending words from preMask
                    for(int k = 0; k < n; ++k)
                    {
                        if(((preMask) & (1 << k)) == 0) // kth word is not used
                            continue;
                        
                        if(dp[mask][set].first > dp[preMask][k].first + cost[k][set])
                        {
                            dp[mask][set] = {dp[preMask][k].first + cost[k][set], dp[preMask][k].second + words[set].substr(words[set].size()-cost[k][set])};
                        }
                    }
                }
                if(mask == end && dp[mask][set].first < minCost)
                {
                    minCost = dp[mask][set].first;
                    ans = dp[mask][set].second;
                }
            }
        }
        
        return ans;
    }
};
