// By Vishwam Shriram Mundada
// https://leetcode.com/problems/cheapest-flights-within-k-stops/
// Decent, BFS
// IDK why Dijkstra is giving TLE

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
