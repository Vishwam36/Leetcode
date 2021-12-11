// By Vishwam Shriram Mundada
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/121/dynamic-programming/860/
// Decent

/*
Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.

Example 1:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

Constraints:
    1 <= nums.length <= 2 * 10^4
    -10 <= nums[i] <= 10
    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
*/

class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> pre(n, 0);
        vector<int> suf(n, 0);
        
        int pro = 1;
        for(int i = 0; i < n; ++i)
        {
            pro *= nums[i];
            pre[i] = pro;
            
            if(pro == 0)
                pro = 1;
        }
        
        pro = 1;
        for(int i = n-1; i >= 0; --i)
        {
            pro *= nums[i];
            suf[i] = pro;
            
            if(pro == 0)
                pro = 1;
        }
        
        int ans = INT_MIN;
        for(int i = 0; i < n; ++i)
            ans = max({ans, pre[i], suf[i]});
        
        return ans;
    }
};
