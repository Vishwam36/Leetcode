// By Vishwam Shriram Mundada
// https://leetcode.com/problems/redundant-connection/
// Decent

// App 1:
// Brute Force

class Solution {
public:
    bool check(vector<int> adj[], int n)
    {
        int vis[n+1];
        for(int i = 1; i <= n; ++i)
            vis[i] = 0;
        
        queue<pair<int, int> > q;
        q.push({1, 0});
        vis[1] = 1;
        
        while(!q.empty())
        {
            pair<int, int> p = q.front();
            int curr = p.first;
            int parent = p.second;
            q.pop();
            
            for(int i = 0; i < adj[curr].size(); ++i)
            {
                int child = adj[curr][i];
                if(vis[child] && child != parent)
                    return false;
                
                else if(!vis[child] && child != parent)
                {
                    q.push({child, curr});
                    vis[child] = 1;
                }
            }
        }
        
        for(int i = 1; i <= n; ++i)
            if(vis[i] == 0)
                return false;
        
        return true;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        vector<int> ans(2);
        int n = edges.size();
        for(int i = 0; i < n; ++i)
        {
            vector<int> adj[n+1];
            for(int j = 0; j < n; ++j)
            {
                if(i != j)
                {
                    adj[edges[j][0]].push_back(edges[j][1]);
                    adj[edges[j][1]].push_back(edges[j][0]);
                }
            }
            bool temp = check(adj, n);
            if(temp)
            {
                ans[0] = edges[i][0];
                ans[1] = edges[i][1];
            }
        }
        return ans;
    }
};

// App 2:
// Union set

class Solution {
public:
    vector<int> ans = {0, 0};
    vector<int> p;
    
    int find_parent(int a)
    {
        while(a != p[a])
            a = p[a];
        
        return a;
    }
    
    void union_set(int a, int b)
    {
        int pa = find_parent(a);
        int pb = find_parent(b);
        
        if(pa == pb)
            ans = {a, b};
        
        p[pb] = pa;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n = edges.size();
        p.resize(n+1);
        for(int i = 0; i <= n; ++i)
            p[i] = i;
        
        for(int i = 0; i < n; ++i)
            union_set(edges[i][0], edges[i][1]);
        
        return ans;
    }
};
