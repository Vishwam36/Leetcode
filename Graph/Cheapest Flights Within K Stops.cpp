// By Vishwam Shriram Mundada
// https://leetcode.com/problems/cheapest-flights-within-k-stops/
// Decent

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<pair<int, int> > v[n];
        
        for(int i = 0; i < flights.size(); ++i)
            v[flights[i][0]].push_back( { flights[i][1], flights[i][2] } );
        
        priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > pq;
        pq.push({0, src, k});
        
        while(!pq.empty())
        {
            vector<int> curr = pq.top();
            pq.pop();
            
            int cost = curr[0];
            int currNode = curr[1];
            int stops = curr[2];
            
            if(currNode == dst)
                return cost;
            
            if(stops < 0)
                continue;
            
            for(int i = 0; i < v[currNode].size(); ++i)
            {
                int nextNode = v[currNode][i].first;
                int nextCost = v[currNode][i].second;
                
                pq.push({cost + nextCost, nextNode, stops-1});
            }
        }
        return -1;
    }
};
