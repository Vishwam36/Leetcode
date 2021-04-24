// By Vishwam Shriram Mundada
// https://leetcode.com/problems/single-threaded-cpu/submissions/
// Decent question

class Solution {
public:
    typedef long long ll;
    struct cmp
    {
        bool operator()(vector<int> &p, vector<int> &q)
        {
            // is start time is equal then take lesser index first
            if(p[1] == q[1])
                return p[2] > q[2];
            
            // else take lesser start time first
            return p[1] > q[1];
        }
    };
    
    static bool cmpTasks(vector<int> &a, vector<int> &b)
    {
        if(a[0] == b[0])
            return a[1] < b[1];
        
        // lesser start time comes first
        return a[0] < b[0];
    }

    vector<int> getOrder(vector<vector<int>>& tasks) 
    {
        ll time = 1;
        vector<int> ans;
        
        vector<vector<int> > copy;
        for(int i = 0; i < tasks.size(); ++i)
            copy.push_back( {tasks[i][0], tasks[i][1], i} );
        
        sort(copy.begin(), copy.end(), cmpTasks);
        priority_queue<vector<int>, vector<vector<int> > , cmp> pq;
        
        int i = 0;
        while(i < copy.size() || !pq.empty())
        {
            if(pq.empty())
            {
                int j = i;
                while(i < copy.size() && copy[j][0] == copy[i][0])
                {
                    pq.push(copy[i]);
                    ++i;
                }
            }
            else
            {
                vector<int> p = pq.top();
                pq.pop();
                int index = p[2];
                int duration = p[1];
                time = max(time + (ll)duration, (ll)p[0] + (ll)duration);
                ans.push_back(index);
                while(i < copy.size() && copy[i][0] <= time)
                {
                    pq.push(copy[i]);
                    ++i;
                }
            }
        }
        return ans;
    }
};
