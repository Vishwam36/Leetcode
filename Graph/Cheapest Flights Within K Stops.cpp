// By Vishwam Shriram Mundada
// https://leetcode.com/problems/cheapest-flights-within-k-stops/
// Decent, BFS
// IDK why Dijkstra is giving TLE

/*
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a 
flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

Example 1:
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation: The graph is shown.
The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.

Example 2:
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation: The graph is shown.
The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.

Constraints:
    1 <= n <= 100
    0 <= flights.length <= (n * (n - 1) / 2)
    flights[i].length == 3
    0 <= fromi, toi < n
    fromi != toi
    1 <= pricei <= 104
    There will not be any multiple flights between two cities.
    0 <= src, dst, k < n
    src != dst
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<pair<int, int> > adj[n];
        for(auto f : flights)
            adj[f[0]].push_back( {f[1], f[2]} );
        
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        queue<pair<int, int> > q;
        q.push({src, 0});
        
        while(!q.empty() && k >= 0)
        {
            int len = q.size();
            while(len--)
            {
                int curr = q.front().first;
                int d = q.front().second;
                q.pop();
                                
                for(int i = 0; i < adj[curr].size(); ++i)
                {
                    auto next = adj[curr][i];
                    
                    if(dist[next.first] > d + next.second) // we have to use here d and not dist[..] because we cant use updated distances
                    {
                        dist[next.first] = d + next.second;
                        q.push({next.first, dist[next.first]});
                    }
                }
            }
            --k;
        }
        
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
