// By Vishwam Shriram Mundada
// https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/
// Good, DP, precalculation

/*
Given an integer array nums and an integer k, find three non-overlapping subarrays of length k with maximum sum and return them.

Return the result as a list of indices representing the starting position of each interval (0-indexed). 
If there are multiple answers, return the lexicographically smallest one.

Example 1:
Input: nums = [1,2,1,2,6,7,5,1], k = 2
Output: [0,3,5]
Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.

Example 2:
Input: nums = [1,2,1,2,1,2,1,2,1], k = 2
Output: [0,2,4]

Constraints:
    1 <= nums.length <= 2 * 10^4
    1 <= nums[i] < 2^16
    1 <= k <= floor(nums.length / 3)
*/

// REF : https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/discuss/108231/C%2B%2BJava-DP-with-explanation-O(n)

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int> preSum = {0}, left(n, 0), right(n, n-k), ans;
        
        for(auto num : nums)
            preSum.push_back(preSum.back() + num);
        
        for(int i = k, sum = preSum[k]; i < n; ++i)
        {
            if(sum < preSum[i+1] - preSum[i+1-k])
            {
                sum = preSum[i+1] - preSum[i+1-k];
                left[i] = i-k+1;
            }
            else
            {
                left[i] = left[i-1];
            }
        }
        
        for(int i = n-k-1, sum = preSum[n]-preSum[n-k]; i >= 0; --i)
        {
            if(sum <= preSum[i+k] - preSum[i])
            {
                sum = preSum[i+k] - preSum[i];
                right[i] = i;
            }
            else
            {
                right[i] = right[i+1];
            }
        }
        
        int maxsum = INT_MIN;
        for(int i = k; i <= n-2*k; ++i)
        {
            int l = left[i-1], r = right[i+k];
            int sum = preSum[i+k] - preSum[i]
                    + preSum[l+k] - preSum[l]
                    + preSum[r+k] - preSum[r];
            
            if(sum > maxsum)
            {
                maxsum = sum;
                ans = {l, i, r};
            }
        }
        
        return ans;
    }
};
