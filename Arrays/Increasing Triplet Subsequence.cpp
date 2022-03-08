// By Vishwam Shriram Mundada
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/781/
// Decent

/*
Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. 
If no such indices exists, return false.

Example 1:
Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.

Example 2:
Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.

Example 3:
Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.

Constraints:
    1 <= nums.length <= 5 * 10^5
    -2^31 <= nums[i] <= 2^31 - 1
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums)
    {
        int n = nums.size();
        int a = INT_MAX, b = INT_MAX, c = INT_MIN;
        
        for(int i = 0; i < n; ++i)
        {
            if(nums[i] < a)
                a = nums[i];
            else if(nums[i] > a && b > nums[i])
                b = nums[i];
            else if(c < nums[i] && nums[i] > b)
                c = nums[i];
        }
        return a < b && b < c;
    }
};
