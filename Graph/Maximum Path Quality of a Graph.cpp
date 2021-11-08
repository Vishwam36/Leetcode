// By Vishwam Shriram Mundada
// https://leetcode.com/problems/maximum-path-quality-of-a-graph/
// Brute force DFS

/*
There is an undirected graph with n nodes numbered from 0 to n - 1 (inclusive). You are given a 0-indexed integer array values where values[i] is the value of the ith node.
You are also given a 0-indexed 2D integer array edges, where each edges[j] = [uj, vj, timej] indicates that there is an undirected edge between the nodes uj and vj, 
and it takes timej seconds to travel between the two nodes. Finally, you are given an integer maxTime.

A valid path in the graph is any path that starts at node 0, ends at node 0, and takes at most maxTime seconds to complete. You may visit the same node multiple times. 
The quality of a valid path is the sum of the values of the unique nodes visited in the path (each node's value is added at most once to the sum).

Return the maximum quality of a valid path.

Note: There are at most four edges connected to each node.

Example 1:
Input: values = [0,32,10,43], edges = [[0,1,10],[1,2,15],[0,3,10]], maxTime = 49
Output: 75
Explanation:
One possible path is 0 -> 1 -> 0 -> 3 -> 0. The total time taken is 10 + 10 + 10 + 10 = 40 <= 49.
The nodes visited are 0, 1, and 3, giving a maximal path quality of 0 + 32 + 43 = 75.

Example 2:
Input: values = [5,10,15,20], edges = [[0,1,10],[1,2,10],[0,3,10]], maxTime = 30
Output: 25
Explanation:
One possible path is 0 -> 3 -> 0. The total time taken is 10 + 10 = 20 <= 30.
The nodes visited are 0 and 3, giving a maximal path quality of 5 + 20 = 25.

Example 3:
Input: values = [1,2,3,4], edges = [[0,1,10],[1,2,11],[2,3,12],[1,3,13]], maxTime = 50
Output: 7
Explanation:
One possible path is 0 -> 1 -> 3 -> 1 -> 0. The total time taken is 10 + 13 + 13 + 10 = 46 <= 50.
The nodes visited are 0, 1, and 3, giving a maximal path quality of 1 + 2 + 4 = 7.

Example 4:
Input: values = [0,1,2], edges = [[1,2,10]], maxTime = 10
Output: 0
Explanation: 
The only path is 0. The total time taken is 0.
The only node visited is 0, giving a maximal path quality of 0.

Constraints:
n == values.length
1 <= n <= 1000
0 <= values[i] <= 108
0 <= edges.length <= 2000
edges[j].length == 3
0 <= uj < vj <= n - 1
10 <= timej, maxTime <= 100
All the pairs [uj, vj] are unique.
There are at most four edges connected to each node.
The graph may not be connected.
*/

/*
HINT : 
Read problem constraints carefully. Given that maxTime <= 100 and time_j >= 10. So we can make no more than 10 steps in our graph. So, all we need to do is to run dfs
We have at most 10 steps, and it is also given that each node have at most degree 4, so in total we can make no more than 4^10 states. That is why we will not get TLE.
*/

class Solution {
public:
    int ans = 0;
    
    void dfs(int node, vector<pair<int, int> > adj[], vector<int>& values, vector<int>& vis, int maxTime, int gain)
    {
        if(node == 0)
            ans = max(ans, gain);
        
        for(auto p : adj[node])
        {
            int child = p.first;
            int weight = p.second;
            
            if(maxTime-weight >= 0)
            {
                if(vis[child] == 0)
                {
                    vis[child] = 1;
                    dfs(child, adj, values, vis, maxTime-weight, gain + values[child]);
                    vis[child] = 0;
                }
                else
                {
                    dfs(child, adj, values, vis, maxTime-weight, gain);
                }
            }
        }
    }
    
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime)
    {
        int n = values.size();
        vector<pair<int, int> > adj[n];
        
        for(auto e : edges)
        {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vector<int> vis(n, 0);
        vis[0] = 1;
        dfs(0, adj, values, vis, maxTime, values[0]);
        return ans;
    }
};
