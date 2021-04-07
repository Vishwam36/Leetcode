// By Vishwam Shriram Mundada
// https://leetcode.com/problems/minimum-height-trees/
// Decent

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
    {
        vector<int> ans;
        vector<int> adj[n];
        int vis[n];
        int indegree[n];
        
        if(n <= 2)
        {
            for(int i = 0; i < n; ++i)
                ans.push_back(i);
            
            return ans;
        }
        
        for(int i = 0; i < n; ++i)
        {
            indegree[i] = 0;
            vis[i] = 0;
        }
        
        for(int i = 0; i < edges.size(); ++i)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
        }
        
        queue<pair<int, int> > q;
        
        for(int i = 0; i < n; ++i)
        {
            if(indegree[i] == 1)
            {
                q.push({i, 0});
                indegree[i]--;
                vis[i] = 1;
            }
        }
        int ml = 0;
        int l = 0;
        while(!q.empty())
        {
            pair<int, int> p = q.front();
            int curr = p.first;
            l = p.second;
            q.pop();
            
            int n = 0;
            for(int i = 0; i < adj[curr].size(); ++i)
            {
                int child = adj[curr][i];
                if(!vis[child])
                {
                    indegree[child]--;
                    if(indegree[child] <= 1)
                    {
                        q.push({child, l+1});
                        ml = max(ml, l+1);
                        vis[child] = 1;
                    }
                    n++;
                }
            }
            if(n == 0 && l == ml)
                ans.push_back(curr);
        }
        
        return ans;
    }
};
