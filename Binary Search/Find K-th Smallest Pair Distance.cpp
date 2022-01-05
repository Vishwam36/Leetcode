// By Vishwam Shriram Mundada
// https://leetcode.com/problems/find-k-th-smallest-pair-distance/
// Good question

/*
The distance of a pair of integers a and b is defined as the absolute difference between a and b.

Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.

Example 1:
Input: nums = [1,3,1], k = 1
Output: 0
Explanation: Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.

Example 2:
Input: nums = [1,1,1], k = 2
Output: 0

Example 3:
Input: nums = [1,6,1], k = 3
Output: 5

Constraints:
    n == nums.length
    2 <= n <= 10^4
    0 <= nums[i] <= 106
    1 <= k <= n * (n - 1) / 2
*/

// REF : https://www.youtube.com/watch?v=ym93rTBR4j8

class Solution {
public:
    int rank(vector<int> &nums, int diff)
    {
        int l = 0, n = nums.size(), ans = 0;
        
        for(int r = 1; r < n; ++r)
        {   
            while(nums[r] - nums[l] > diff)
                ++l;
            
            ans += r-l;
        }
        
        return ans;
    }
    
    int smallestDistancePair(vector<int>& nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int l = 0, r = nums[n-1]-nums[0];
        
        while(r-l > 1)
        {
            int mid = (l+r)/2;
            
            if(rank(nums, mid) >= k)
                r = mid;
            else
                l = mid;
        }
        
        if(rank(nums, l) >= k)
            return l;
        return r;
    }
};
