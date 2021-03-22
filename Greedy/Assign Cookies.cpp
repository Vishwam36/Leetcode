// By Vishwam Shriram Mundada
// https://leetcode.com/problems/assign-cookies/
// V.Easy

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        if(g.size() == 0 || s.size() == 0)
            return 0;
        
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());
        
        int j = 0, ans = 0;
        for(int i = 0; i < g.size(); ++i)
        {
            if(s[j] >= g[i])
            {
                ++ans;
                ++j;
            }
            if(j == s.size())
            {
                return ans;
            }
        }
        
        return ans;
    }
};
