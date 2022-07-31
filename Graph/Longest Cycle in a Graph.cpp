// By Vishwam Shriram Mundada
// https://leetcode.com/problems/longest-cycle-in-a-graph/
// Decent

class Solution {
public:
    int ans = -1;
    
    void cycle(int st, vector<int> &vis, vector<int> &path, vector<int> &edges)
    {
        if(st == -1)
            return;
        
        if(vis[st])
        {
            int idx = -1;
            for(int i = 0; i < path.size(); ++i)
                if(st == path[i])
                {
                    idx = i;
                    break;
                }
            
            if(idx != -1)
                ans = max(ans, (int)path.size()-idx);
            return;
        }
        
        vis[st] = 1;
        path.push_back(st);
        cycle(edges[st], vis, path, edges);
    }
    
    int longestCycle(vector<int>& edges)
    {
        int n = edges.size(), ms = -1;
        vector<int> vis(n, 0);
        
        for(int i = 0; i < n; ++i)
            if(!vis[i])
            {
                vector<int> path;
                cycle(i, vis, path, edges);
            }
        
        return ans;
    }
};
