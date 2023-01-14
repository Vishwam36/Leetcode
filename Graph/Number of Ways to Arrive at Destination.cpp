// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/
// Decent

class Solution {
public:
    long long mod = 1000000007;
    int find(long long src, long long n, vector<pair<long long, long long> > adj[])
    {
        priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, greater<pair<long long, long long> > > pq;
        pq.push({src, 0});

        vector<long long> dist(n, LONG_MAX);
        vector<long long> ways(n, 0);
        dist[src] = 0;
        ways[src] = 1;
        while(!pq.empty())
        {
            auto p = pq.top(); pq.pop();
            long long distSoFar = p.first;
            long long curr = p.second;

            if(distSoFar > dist[curr])
            {
                continue;
            }

            for(auto next : adj[curr])
            {
                long long nextNode = next.first;
                long long nextDist = next.second;

                if(dist[nextNode] > distSoFar + nextDist)
                {
                    dist[nextNode] = distSoFar + nextDist;
                    pq.push({dist[nextNode], nextNode});
                    ways[nextNode] = ways[curr];
                }
                else if(dist[nextNode] == distSoFar + nextDist)
                {
                    ways[nextNode] = (ways[nextNode] + ways[curr]) % mod;
                }
            }
        }
        return ways[n-1];
    }

    int countPaths(int n, vector<vector<int>>& roads) 
    {
        vector<pair<long long, long long> > adj[n];
        for(auto r : roads)
        {
            long long u = r[0];
            long long v = r[1];
            long long t = r[2];

            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }
        
        return find(0, n, adj);
    }
};
