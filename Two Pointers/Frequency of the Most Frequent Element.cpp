// By Vishwam Shriram Mundada
// https://leetcode.com/problems/frequency-of-the-most-frequent-element/
// Decent

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) 
    {
        long long left = 0, right = 0, ans = 1, sum = 0;
        sort(nums.begin(), nums.end());
        
        for(right = 0; right < nums.size(); ++right)
        {
            sum += nums[right];
            
            if((right-left+1) * nums[right] - sum > (long long)k)
            {
                sum -= nums[left];
                left++;
            }
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};
