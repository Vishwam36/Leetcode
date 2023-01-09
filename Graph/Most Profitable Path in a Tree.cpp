// https://leetcode.com/problems/most-profitable-path-in-a-tree/description/
// long implementation

class Solution {
public:
    int maxScore = INT_MIN;

    void rec(int curr, int par, vector<int> adj[], vector<int> &visTime, vector<int> &a, int score, int t, vector<int> &vis)
    {
        int temp = (curr == 0 ? 0 : score);
        if(visTime[curr] == t)
        {
            temp += a[curr]/2;
        }
        else if(t < visTime[curr] || !vis[curr])
        {
            temp += a[curr]; 
        }

        if(adj[curr].size() == 1 && curr != 0)
        {
            maxScore = max(maxScore, temp);
            return;
        }

        for(auto next : adj[curr])
        {
            if(next != par)
            {
                rec(next, curr, adj, visTime, a, temp, t+1, vis);
            }
        }
    }

    vector<int> p;
    bool getPath(int curr, int par, vector<int> adj[])
    {
        p.push_back(curr);
        if(curr == 0)
        {
            return true;
        }
        for(auto next : adj[curr])
        {
            if(next != par && getPath(next, curr, adj))
            {
                return true;
            }
        }
        p.pop_back();
        return false;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& a) 
    {
        int n = a.size();
        vector<int> adj[n];

        for(auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> visTime(n, 0);
        visTime[bob] = 0;
        getPath(bob, -1, adj);
        vector<int> vis(n, 0);

        int t = 0;
        for(auto x : p)
        {
            vis[x]++;
            visTime[x] = t++;
        }

        rec(0, -1, adj, visTime, a, INT_MIN, 0, vis);
        return maxScore;
    }
};
