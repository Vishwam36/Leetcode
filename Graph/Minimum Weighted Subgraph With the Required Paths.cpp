// By Vishwam Shriram Mundada
// https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths/
// Good question

/*
You are given an integer n denoting the number of nodes of a weighted directed graph. The nodes are numbered from 0 to n - 1.

You are also given a 2D integer array edges where edges[i] = [fromi, toi, weighti] denotes that there exists a directed edge from fromi to toi with weight weighti.

Lastly, you are given three distinct integers src1, src2, and dest denoting three distinct nodes of the graph.

Return the minimum weight of a subgraph of the graph such that it is possible to reach dest from both src1 and src2 via a set of edges of this subgraph. 
In case such a subgraph does not exist, return -1.

A subgraph is a graph whose vertices and edges are subsets of the original graph. The weight of a subgraph is the sum of weights of its constituent edges.

Example 1:
Input: n = 6, edges = [[0,2,2],[0,5,6],[1,0,3],[1,4,5],[2,1,1],[2,3,3],[2,3,4],[3,4,2],[4,5,1]], src1 = 0, src2 = 1, dest = 5
Output: 9
Explanation:
The above figure represents the input graph.
The blue edges represent one of the subgraphs that yield the optimal answer.
Note that the subgraph [[1,0,3],[0,5,6]] also yields the optimal answer. It is not possible to get a subgraph with less weight satisfying all the constraints.

Example 2:
Input: n = 3, edges = [[0,1,1],[2,1,1]], src1 = 0, src2 = 1, dest = 2
Output: -1
Explanation:
The above figure represents the input graph.
It can be seen that there does not exist any path from node 1 to node 2, hence there are no subgraphs satisfying all the constraints.

Constraints:
    3 <= n <= 10^5
    0 <= edges.length <= 10^5
    edges[i].length == 3
    0 <= fromi, toi, src1, src2, dest <= n - 1
    fromi != toi
    src1, src2, and dest are pairwise distinct.
    1 <= weight[i] <= 10^5
*/


// REF : https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths/discuss/1844091/C%2B%2B-Dijkstra-3-times-with-illustration

class Solution {
public:
    #define pll pair<long long, long long>
    
    void minDist(int n, int src, vector<pll> adj[], vector<long long> &d)
    {
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        pq.push({src, 0});
        d[src] = 0;
        
        while(!pq.empty())
        {
            auto p = pq.top(); pq.pop();
            auto curr = p.first;
            auto dist = p.second;
            
            if(dist > d[curr])
                continue;
                        
            for(auto& p : adj[curr])
            {
                auto v = p.first, w = p.second;
                if(dist + w < d[v])
                {
                    d[v] = dist + w;
                    pq.push({v, d[v]});
                }
            }
        }
    }
    
    long long minimumWeight(int n, vector<vector<int>>& edges, int a, int b, int dest) 
    {
        vector<pll> adj1[n], adj2[n];
        map<pll, long long> m1, m2;
        for(auto& e : edges)
        {
            long long u = e[0], v = e[1], w = e[2];
            adj1[u].push_back({v,w});
            adj2[v].push_back({u,w});
        }
        
        vector<long long> da(n, LLONG_MAX), db(n, LLONG_MAX), dd(n, LLONG_MAX);
        minDist(n, a, adj1, da);
        minDist(n, b, adj1, db);
        minDist(n, dest, adj2, dd);
        
        long long ans = LLONG_MAX;
        for(int i = 0; i < n; ++i)
            if(da[i] != LLONG_MAX && db[i] != LLONG_MAX && dd[i] != LLONG_MAX)
                ans = min(ans, da[i] + db[i] + dd[i]);
        
        return (ans == LLONG_MAX ? -1 : ans);
    }
};
