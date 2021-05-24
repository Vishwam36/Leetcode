// By Vishwam Shriram Mundada
// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
// Easy, just lengthy implementation

/*
There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge 
between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, 
If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

Example 1:
Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
Output: 3
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2] 
City 1 -> [City 0, City 2, City 3] 
City 2 -> [City 0, City 1, City 3] 
City 3 -> [City 1, City 2] 
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.

Example 2:
Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
Output: 0
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 2 for each city are:
City 0 -> [City 1] 
City 1 -> [City 0, City 4] 
City 2 -> [City 3, City 4] 
City 3 -> [City 2, City 4]
City 4 -> [City 1, City 2, City 3] 
The city 0 has 1 neighboring city at a distanceThreshold = 2.

Constraints:
    2 <= n <= 100
    1 <= edges.length <= n * (n - 1) / 2
    edges[i].length == 3
    0 <= fromi < toi < n
    1 <= weighti, distanceThreshold <= 10^4
    All pairs (fromi, toi) are distinct.
*/

class Solution {
public:
    void dijkstra(int src, int dt, int n, vector<pair<int, int> > adj[], vector<int> v[])
    {
        vector<int> dist(n, INT_MAX);
        vector<bool> vis(n, false);
        
        priority_queue<pair<int, int> , vector<pair<int, int> > , greater<pair<int, int> > > pq;
        pq.push({0, src});
        dist[src] = 0;
        
        while(!pq.empty())
        {
            pair<int, int> p = pq.top();
            int curr = p.second;
            int curr_d = p.first;
            pq.pop();
            
            if(vis[curr])
                continue;
            
            vis[curr] = 1;
            
            for(int i = 0; i < adj[curr].size(); ++i)
            {
                pair<int, int> pc = adj[curr][i];
                if(!vis[pc.first] && curr_d + pc.second < dist[pc.first] && curr_d + pc.second <= dt)
                {
                    dist[pc.first] = curr_d + pc.second;
                    pq.push({dist[pc.first], pc.first});
                }
            }
        }
        
        for(int i = 0; i < n; ++i)
            if(dist[i] <= dt)
                v[src].push_back(i);
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        vector<int> v[n];
        vector<pair<int, int> > adj[n];
        
        for(int i = 0; i < edges.size(); ++i)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            int w = edges[i][2];
            
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }
        
        for(int i = 0; i < n; ++i)
            dijkstra(i, distanceThreshold, n, adj, v);
        
        int minSize = INT_MAX, ans = -1;
        for(int i = 0; i < n; ++i)
            if(v[i].size() <= minSize)
            {
                minSize = v[i].size();
                ans = i;
            }
        
        return ans;
    }
};
