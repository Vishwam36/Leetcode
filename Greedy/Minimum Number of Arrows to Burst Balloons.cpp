// By Vishwam Shriram Mundada
// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
// Easy

bool cmp(vector<int> &v1, vector<int> &v2)
{
    if(v1[1] == v2[1])
        return v1[0] < v2[0];
    
    return v1[1] < v2[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        sort(points.begin(), points.end(), cmp);
        
        if(points.size() == 0)
            return 0;
        
        int ans = 1, last = points[0][1];
        for(int i = 1; i < points.size(); ++i)
        {
            if(points[i][0] > last)
            {
                last = points[i][1];
                ans++;
            }
        }
        return ans;
    }
};
