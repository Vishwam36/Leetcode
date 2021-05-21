// By Vishwam Shriram Mundada
// https://leetcode.com/problems/search-in-rotated-sorted-array/
// Decent

/*
There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that 
the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1
 
Constraints:
1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is guaranteed to be rotated at some pivot.
-104 <= target <= 104
*/

// First find the index k at which array is rotated
// then binary search on either halves depending on target

class Solution {
public:
    int search(vector<int>& nums, int l, int r, int target)
    {
        int mid;
        while(r-l > 1)
        {
            mid = (l+r)/2;
            if(nums[mid] == target)
                return mid;
            
            if(target > nums[mid])
                l = mid+1;
            else
                r = mid-1;
        }
        if(nums[l] == target)
            return l;
        if(nums[r] == target)
            return r;
        return -1;
    }
    
    int search(vector<int>& nums, int target) 
    {
        int l = 0, r = nums.size()-1, mid;
        if(nums[0] <= nums.back())
            return search(nums, l, r, target);
        
        while(r-l > 1)
        {
            mid = (l+r)/2;
            if(nums[mid] > nums[mid+1])
                break;
            
            if(nums[mid] > nums[0])
                l = mid+1;
            else
                r = mid-1;
        }
        if(nums[l] > nums[l+1])
            mid = l;
        else if(r < nums.size()-1 && nums[r] > nums[r+1])
            mid = r;
        
        int k = mid;
        if(target >= nums[0])
            return search(nums, 0, k, target);
        return search(nums, k+1, nums.size()-1, target);
    }
};
