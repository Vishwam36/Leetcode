// By Vishwam Shriram Mundada
// https://leetcode.com/problems/maximum-average-pass-ratio/
// Good question

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) 
    {
        priority_queue<pair<double, int> > pq;
        pair<double, int> temp;
        
        int n = classes.size();
        double ans = 0;
        
        for(int i = 0; i < n; ++i)
        {
            double pass = classes[i][0];
            double total = classes[i][1];
            
            double increase = ((pass+1)/(total+1)) - (pass/total);
            
            pq.push({increase, i});
            
            ans += pass/total;
        }
        
        while(extraStudents--)
        {
            temp = pq.top();
            pq.pop();
            
            ans += temp.first;
            
            int i = temp.second;
            classes[i][0]++;
            classes[i][1]++;
            
            double pass = classes[i][0];
            double total = classes[i][1];
            
            double increase = ((pass+1)/(total+1)) - (pass/total);
            
            pq.push({increase, i});
        }
        
        ans = ans / (double)n;
        return ans;
    }
};
