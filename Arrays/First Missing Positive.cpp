// By Vishwam Shriram Mundada
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/832/
// Good

/*
Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.

Example 1:
Input: nums = [1,2,0]
Output: 3

Example 2:
Input: nums = [3,4,-1,1]
Output: 2

Example 3:
Input: nums = [7,8,9,11,12]
Output: 1

Constraints:
    1 <= nums.length <= 5 * 10^5
    -231 <= nums[i] <= 231 - 1
*/


// REF : https://www.youtube.com/watch?v=-lfHWWMmXXM&t=539s

class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int n = nums.size();
        int i = 0;
        while(i < n)
        {
            if(nums[i] == i+1 || nums[i] <= 0 || nums[i] > n)
            {
                i++;
                continue;
            }
            if(nums[i] != nums[nums[i]-1])
                swap(nums[i], nums[nums[i]-1]);
            else
                ++i;
        }
        
        for(i = 0; i < n; ++i)
            if(nums[i] != i+1)
                return i+1;
        
        return n+1;
    }
};
