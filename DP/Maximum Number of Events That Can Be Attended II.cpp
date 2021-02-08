// By Vishwam Shriram Mundada
// https://leetcode.com/contest/biweekly-contest-45/problems/maximum-number-of-events-that-can-be-attended-ii/
// Good question

bool cmp(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) 
    {
        // sort according to last date
        sort(events.begin(), events.end(), cmp);
        int n = events.size();
        
        // dp[i][] => i is number of events
        // dp[][j] => j is maximum events allowed
        int dp[n+1][k+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i = 1; i <= n; ++i)
        {
            // last_attended represents index of last event that can be attended if ith event is attended
            int last_attended = 0;
            for(int j = i - 1; j > 0; --j)
            {
                if(events[j-1][1] < events[i-1][0])
                {
                    last_attended = j;
                    break;
                }
            }
            for(int j = 1; j <= k; ++j)
            {
                // dp[i][j] = max(maximum total value till last possible event + value of current event (attending ith event), 
                //                value of last index (not attending ith event))
                dp[i][j] = max(dp[last_attended][j-1] + events[i-1][2], dp[i-1][j]);
            }
        }
        return dp[n][k];
    }
};
