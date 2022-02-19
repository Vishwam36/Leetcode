// By Vishwam Shriram Mundada
// https://leetcode.com/problems/wiggle-sort-ii/
// Decent

/*
Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
You may assume the input array always has a valid answer.

Example 1:
Input: nums = [1,5,1,1,6,4]
Output: [1,6,1,5,1,4]
Explanation: [1,4,1,5,1,6] is also accepted.

Example 2:
Input: nums = [1,3,2,2,3,1]
Output: [2,3,1,3,1,2]

Constraints:
    1 <= nums.length <= 5 * 104
    0 <= nums[i] <= 5000
    It is guaranteed that there will be an answer for the given input nums.
	
Follow Up: Can you do it in O(n) time and/or in-place with O(1) extra space?
*/


// We could have done sorting but since nums[i] <= 5000, we can use hashing 
// TC : O(N) + O(5000)
// SC : O(5000)

class Solution {
public:
    void wiggleSort(vector<int>& nums) 
    {
        vector<int> f(5001, 0);
        int n = nums.size();
        for(int i = 0; i < n; ++i)
            f[nums[i]]++;
        
        int x = 5000;
        for(int i = 1; i < n; i+=2)
        {
            while(f[x] == 0)
                x--;
            nums[i] = x;
            f[x]--;
        }
        
        for(int i = 0; i < n; i+=2)
        {
            while(f[x] == 0)
                x--;
            nums[i] = x;
            f[x]--;
        }
    }
};
