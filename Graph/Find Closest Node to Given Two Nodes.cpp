// By Vishwam Shriram Mundada
// https://leetcode.com/problems/find-closest-node-to-given-two-nodes/
// Decent

class Solution {
public:
    pair<int, int> find(vector<int>& e, int node1, int node2)
    {
        map<int, int> m1, m2;
        int dist = 0;
        m1[node1] = 0;
        
        int t = node1;
        while(1)
        {
            int next = e[t];
            if(next != -1 && m1.find(next) == m1.end())
                m1[next] = ++dist;
            else
                break;
            
            t = next;
        }
        
        t = node2;
        m2[node2] = 0;
        dist = 0;
        
        while(1)
        {
            if(m1.find(t) != m1.end())
                return {t, max(m1[t], m2[t])};
            
            int next = e[t];
            if(next != -1 && m2.find(next) == m2.end())
                m2[next] = ++dist;
            else
                break;
            
            t = next;
        }
        return {-1, INT_MAX};
    }
	
    int closestMeetingNode(vector<int>& e, int node1, int node2)
    {
        auto p1 = find(e, node1, node2);
        auto p2 = find(e, node2, node1);
        
        if(p1.second < p2.second)
            return p1.first;
        if(p1.second > p2.second)
            return p2.first;
        
        return min(p1.first, p2.first);
    }
};
