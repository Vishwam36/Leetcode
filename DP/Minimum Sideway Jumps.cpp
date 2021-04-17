// By Vishawam Shriram Mundada
// https://leetcode.com/problems/minimum-sideway-jumps/
// Decent variety

class Solution {
public:
    int rec(vector<int>& obstacles, vector<vector<int> > &dp, int lane, int pos)
    {
        if(pos == obstacles.size() - 2)
            return dp[pos][lane] = 0;
        
        if(dp[pos][lane] != -1)
            return dp[pos][lane];
        
        if(obstacles[pos+1] != lane)
            return dp[pos][lane] = rec(obstacles, dp, lane, pos+1);
        
        int l1, l2;
        if(lane == 1)
        {
            l1 = 2;
            l2 = 3;
        }
        if(lane == 2)
        {
            l1 = 1;
            l2 = 3;
        }
        if(lane == 3)
        {
            l1 = 1;
            l2 = 2;
        }
        
        if(obstacles[pos] == l1)
            return dp[pos][lane] = 1 + rec(obstacles, dp, l2, pos+1);
        
        else if(obstacles[pos] == l2)
            return dp[pos][lane] = 1 + rec(obstacles, dp, l1, pos+1);
        
        else
            return dp[pos][lane] = 1 + min(rec(obstacles, dp, l1, pos+1), rec(obstacles, dp, l2, pos+1));
    }
    
    int minSideJumps(vector<int>& obstacles)
    {
        vector<vector<int> > dp(obstacles.size()+1, vector<int>(4, -1));
        return rec(obstacles, dp, 2, 0);
    }
};
