// By Vishwam Shriram Mundada
// https://leetcode.com/problems/ipo/
// Decent

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& Profits, vector<int>& Capital) 
    {
        vector<pair<int, int> > pc;
        for(int i = 0; i < Profits.size(); ++i)
            pc.push_back( { Capital[i], i } );
        
        sort(pc.begin(), pc.end());
        
        priority_queue<int> pq;
        
        int i = 0;
        while(k--)
        {
            while(i < Profits.size() && w >= pc[i].first)
                pq.push(Profits[pc[i++].second]);
            
            if(!pq.empty())
            {
                w += pq.top();
                pq.pop();
            }
        }
        return w;
    }
};
