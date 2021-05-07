// By Vishwam Shriram Mundada
// https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/
// Decent 

/*
There is an undirected weighted connected graph. You are given a positive integer n which denotes that the graph has n nodes labeled from 1 to n, and an array edges 
where each edges[i] = [ui, vi, weighti] denotes that there is an edge between nodes ui and vi with weight equal to weighti.
A path from node start to node end is a sequence of nodes [z0, z1, z2, ..., zk] such that z0 = start and zk = end and there is an edge between zi and zi+1 
where 0 <= i <= k-1.
The distance of a path is the sum of the weights on the edges of the path. Let distanceToLastNode(x) denote the shortest distance of a path between node n and node x. 
A restricted path is a path that also satisfies that distanceToLastNode(zi) > distanceToLastNode(zi+1) where 0 <= i <= k-1.

Return the number of restricted paths from node 1 to node n. Since that number may be too large, return it modulo 109 + 7.

Example 1:
Input: n = 5, edges = [[1,2,3],[1,3,3],[2,3,1],[1,4,2],[5,2,2],[3,5,1],[5,4,10]]
Output: 3
Explanation: Each circle contains the node number in black and its distanceToLastNode value in blue. The three restricted paths are:
1) 1 --> 2 --> 5
2) 1 --> 2 --> 3 --> 5
3) 1 --> 3 --> 5

Example 2:
Input: n = 7, edges = [[1,3,1],[4,1,2],[7,3,4],[2,5,3],[5,6,1],[6,7,2],[7,5,3],[2,6,4]]
Output: 1
Explanation: Each circle contains the node number in black and its distanceToLastNode value in blue. The only restricted path is 1 --> 3 --> 7.
 
Constraints:
1 <= n <= 2 * 104
n - 1 <= edges.length <= 4 * 104
edges[i].length == 3
1 <= ui, vi <= n
ui != vi
1 <= weighti <= 105
There is at most one edge between any two nodes.
There is at least one path between any two nodes.
*/

class Solution {
public:
    const int MOD = 1000000007;
    
    void dijkstra(int src, int n, vector<int> &dist, vector<pair<int, int> > adj[])
    {
        vector<bool> vis(n+1, 0);
        
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        pq.push({0, src});
        dist[src] = 0;
        
        while(!pq.empty())
        {
            pair<int, int> p = pq.top();
            pq.pop();
            int curr = p.second;
            int currD = p.first;
            
            if(vis[curr])
                continue;
            
            vis[curr] = 1;
            
            for(int i = 0 ; i < adj[curr].size(); ++i)
            {
                pair<int, int> cp = adj[curr][i];
                int child = cp.first;
                int childW = cp.second;
                
                if(vis[child])
                    continue;
                
                if(currD + childW < dist[child])
                {
                    pq.push({currD + childW, child});
                    dist[child] = currD + childW;
                }
            }
        }
    }
    
    long long count(int src, int n, vector<int> &dist, vector<pair<int, int> > adj[], long long dp[])
    {
        if(src == n)
            return 1;
        
        if(dp[src] != -1)
            return dp[src];
        
        int ans = 0;
        for(int i = 0; i < adj[src].size(); ++i)
        {
            pair<int, int> p = adj[src][i];
            int child = p.first;
            int w = p.second;
            int d = dist[child];
            
            if(dist[child] < dist[src])
                ans += count(child, n, dist, adj, dp);
            
            ans %= MOD;
        }
        
        return dp[src] = ans;
    }
    
    int countRestrictedPaths(int n, vector<vector<int>>& edges) 
    {
        long long ans = 0;
        vector<int> dist(n+1, INT_MAX);
        
        vector<pair<int, int> > adj[n+1];
        for(int i = 0; i < edges.size(); ++i)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            int w = edges[i][2];
            
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }
        
        dijkstra(n, n, dist, adj);
        
        long long dp[n+1];
        for(int i = 0; i <= n; ++i)
            dp[i] = -1;
        
        dp[n] = 1;
        return count(1, n, dist, adj, dp);
    }
};
