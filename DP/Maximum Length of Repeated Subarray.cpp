// By Vishwam Shriram Mundada
// https://leetcode.com/problems/maximum-length-of-repeated-subarray/
// Easy

/*
Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

Example 1:
Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].

Example 2:
Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
Output: 5

Constraints:
    1 <= nums1.length, nums2.length <= 1000
    0 <= nums1[i], nums2[i] <= 100
*/

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) 
    {
        int ans = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int> > dp = vector<vector<int> >(n1+1, vector<int>(n2+1, 0));
        
        for(int i = n1-1; i >= 0; -- i)
        {
            for(int j = n2-1; j >= 0; --j)
            {
                if(nums1[i] == nums2[j])
                    dp[i][j] = 1 + dp[i+1][j+1];
                else
                    dp[i][j] = 0;
                
                ans = max(ans, dp[i][j]);
            }
        }
        
        return ans;
    }
};
