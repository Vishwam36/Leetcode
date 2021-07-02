// By Vishwam Shriram Mundada
// https://leetcode.com/problems/is-graph-bipartite/
// Easy, BFS

/*
There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes 
that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. 

The graph has the following properties:

    There are no self-edges (graph[u] does not contain u).
    There are no parallel edges (graph[u] does not contain duplicate values).
    If v is in graph[u], then u is in graph[v] (the graph is undirected).
    The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.

A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and 
a node in set B.

Return true if and only if it is bipartite.

Example 1:
Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.

Example 2:
Input: graph = [[1,3],[0,2],[1,3],[0,2]]
Output: true
Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.

Constraints:
    graph.length == n
    1 <= n <= 100
    0 <= graph[u].length < n
    0 <= graph[u][i] <= n - 1
    graph[u] does not contain u.
    All the values of graph[u] are unique.
    If graph[u] contains v, then graph[v] contains u.
*/

class Solution {
public:
    int n;
    vector<bool> vis;
    unordered_set<int> c1, c2; // sets of 2 colors
    
    bool bfs(int src, vector<vector<int>>& adj)
    {
        queue<int> q;
        q.push(src);
        vis[src] = 1;
        bool f = true;
        c1.insert(src);
        
        // put nodes into 2 sets level wise
        while(!q.empty())
        {
            int len = q.size();
            while(len--)
            {
                int curr = q.front(); q.pop();
                
                for(auto next : adj[curr])
                {
                    if(vis[next])
                    {
                        if(f && c1.find(next) != c1.end()) // ideally next should be in c2
                            return false;
                        if(!f && c2.find(next) != c2.end()) // ideally next should be in c1
                            return false;
                        
                        continue;
                    }
                    
                    if(f)
                        c2.insert(next);
                    else
                        c1.insert(next);
                    
                    q.push(next);
                    vis[next] = 1;
                }
            }
            f = !f;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& adj) 
    {
        int n = adj.size();
        
        vis = vector<bool>(n, false);
        for(int i = 0; i < n; ++i)
            if(!vis[i])
                if(!bfs(i, adj))
                    return false;
        
        return true;
    }
};
