// By Vishwam Shriram Mundada
// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
// Good question

/*
Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.

Example 1:
Input: nums = [4,3,2,3,5,2,1], k = 4
Output: true
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.

Example 2:
Input: nums = [1,2,3,4], k = 3
Output: false

Constraints:
1 <= k <= nums.length <= 16
1 <= nums[i] <= 104
The frequency of each element is in the range [1, 4].
*/

/*
IDEA : 
Assume sum is the sum of nums[] . The dfs process is to find a subset of nums[] which sum equals to sum/k. We use an array visited[] to record 
which element in nums[] is used. Each time when we get a cur_sum = sum/k, we will start from position 0 in nums[] to look up the elements
that are not used yet and find another cur_sum = sum/k
*/

class Solution {
public:
    int requiredSum;
    
    bool rec(int idx, vector<int>& nums, int k, vector<int> &vis, int sum)
    {
        if(k == 1) // we have found k-1 subsets with sum = requiredSum, so ofcourse remaining elements will form sum = requiredSum
            return true;
        
        if(sum == requiredSum) // we got one subset with sum = requiredSum, now find next one
            return rec(0, nums, k-1, vis, 0);
        
        for(int i = idx; i < nums.size(); ++i)
        {
            if(vis[i])
                continue;
            
            sum += nums[i];
            vis[i] = 1;
            
            if(sum <= requiredSum && rec(i+1, nums, k, vis, sum))
                return true;
            
            vis[i] = 0;
            sum -= nums[i];
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) 
    {
        int totalSum = 0;
        for(auto num : nums)
            totalSum += num;
        
        if(totalSum % k != 0 || *max_element(nums.begin(), nums.end()) > totalSum/k)
            return false;
        
        requiredSum = totalSum / k;
        vector<int> vis(nums.size(), 0);
        
        return rec(0, nums, k, vis, 0);
    }
};
