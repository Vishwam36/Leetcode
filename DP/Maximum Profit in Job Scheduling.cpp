// By Vishwam Shriram Mundada
// https://leetcode.com/problems/maximum-profit-in-job-scheduling/
// Decent

/*
We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping 
time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.

Example 1:
Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.

Example 2:
Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job. 
Profit obtained 150 = 20 + 70 + 60.

Example 3:
Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
Output: 6

Constraints:
    1 <= startTime.length == endTime.length == profit.length <= 5 * 104
    1 <= startTime[i] < endTime[i] <= 109
    1 <= profit[i] <= 104
*/

class Solution {
public:
    int last_max(int idx, vector<vector<int> >& v, int dp[])
    {
        int l = 0, r = idx-1, mid, ans = 0;
        
        while(r-l > 1)
        {
            mid = (l+r)/2;
            
            if(v[mid][1] <= v[idx][0])
            {
                l = mid;
                ans = max(ans, dp[mid]);
            }
            else
            {
                r = mid;
            }
        }
        if(v[r][1] <= v[idx][0])
            return max(ans, dp[r]);
        if(v[l][1] <= v[idx][0])
            return max(ans, dp[l]);
        return 0; // no non-overlapping interval found
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        vector<vector<int> > v;
        for(int i = 0; i < profit.size(); ++i)
            v.push_back({startTime[i], endTime[i], profit[i]});
        
        sort(v.begin(), v.end(), [&](vector<int> &v1, vector<int> &v2){
            return v1[1] < v2[1];
        });
        
        int dp[v.size()];
        dp[0] = v[0][2];
        
        for(int i = 1; i < v.size(); ++i)
        {
            int include = v[i][2];
            int exclude = dp[i-1];
                        
            include += last_max(i, v, dp); // pick up maximum non-overlapping ans till now
            
            dp[i] = max(include, exclude);
        }
        
        return dp[v.size()-1];
    }
};
