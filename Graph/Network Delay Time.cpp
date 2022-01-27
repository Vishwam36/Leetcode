// By Vishwam Shriram Mundada
// https://leetcode.com/problems/network-delay-time/
// Decent

/*
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), 
where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the time it takes for all the n nodes to receive the signal. 
If it is impossible for all the n nodes to receive the signal, return -1.

Example 1:
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2

Example 2:
Input: times = [[1,2,1]], n = 2, k = 1
Output: 1

Example 3:
Input: times = [[1,2,1]], n = 2, k = 2
Output: -1

Constraints:
    1 <= k <= n <= 100
    1 <= times.length <= 6000
    times[i].length == 3
    1 <= ui, vi <= n
    ui != vi
    0 <= wi <= 100
    All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
*/

struct cmp {
    bool operator()(pair<int, int> &p1, pair<int, int> &p2)
    {
        return p1.second > p2.second;
    }
};

class Solution {
public:
    bool allVisited(vector<bool> &vis)
    {
        for(auto status : vis)
            if(status == false)
                return false;
        
        return true;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<pair<int, int> > adj[n];
        vector<bool> vis(n, false);
        
        for(auto edge : times)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj[u-1].push_back({v-1, w});
        }
        
        int ans = INT_MAX;
        priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> q;
        q.push({k-1, 0});
        vis[k-1] = 1;
        
        while(!q.empty())
        {
            auto curr = q.top(); q.pop();
            int currNode = curr.first;
            int preTime = curr.second;
            
            vis[currNode] = 1;
            
            if(allVisited(vis))
            {
                ans = min(ans, preTime);
                break;
            }
            
            for(auto p : adj[currNode])
            {
                int next = p.first;
                int time = p.second;
                
                if(!vis[next])
                    q.push({next, time+preTime});
            }
        }
        
        if(!allVisited(vis))
            return -1;
        return ans;
    }
};
