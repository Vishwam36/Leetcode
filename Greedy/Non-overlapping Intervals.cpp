// By Vishwam Shriram Mundada
// https://leetcode.com/problems/non-overlapping-intervals/
// Easy

bool cmp(vector<int> &v1, vector<int> &v2)
{
    if(v1[1] == v2[1])
        return v1[0] < v2[0];
    
    return v1[1] < v2[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end(), cmp);
        
        int last = 0, ans = 0;
        for(int i = 1; i < intervals.size(); ++i)
        {
            if(intervals[i][0] < intervals[last][1])
                ans++;
            
            else
                last = i;
        }
        return ans;
    }
};
