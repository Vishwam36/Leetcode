// By Vishwam Shriram Mundada
// https://leetcode.com/problems/partition-equal-subset-sum/
// Easy

class Solution {
public:
    int total = 0;
    
    vector<vector<int> > dp;
    
    bool rec(int i, vector<int> &v, int sum)
    {
        if(sum == total/2)
            return true;
        if(i == v.size())
            return false;
        
        if(dp[i][sum] != -1)
            return dp[i][sum];
        
        return dp[i][sum] = rec(i+1, v, sum) || (sum + v[i] <= total/2 ? rec(i+1, v, sum + v[i]) : false);
    }
    
    bool canPartition(vector<int>& nums) 
    {
        for(auto& x : nums)
            total += x;
        dp.resize(nums.size()+1, vector<int>(total/2 + 1, -1));
        
        if(total % 2 != 0)
            return false;
        return rec(0, nums, 0);
    }
};
