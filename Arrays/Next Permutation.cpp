// By Vishwam Shriram Mundada
// https://leetcode.com/problems/next-permutation/
// Good question
// Ref : https://leetcode.com/problems/next-permutation/solution/

/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.

Example 1:
Input: nums = [1,2,3]
Output: [1,3,2]

Example 2:
Input: nums = [3,2,1]
Output: [1,2,3]

Example 3:
Input: nums = [1,1,5]
Output: [1,5,1]

Example 4:
Input: nums = [1]
Output: [1]

Constraints:
    1 <= nums.length <= 100
    0 <= nums[i] <= 100
*/

// TC : O(N)
// SC : O(1)
// we can use next_permutation() function directly, but thats not the purpose of this question

class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int n = nums.size();
        int i1=-1, i2=-1;
        for(i1 = n-2; i1 >= 0; --i1)
            if(nums[i1+1] > nums[i1]) // find first decreasing element stored in i1
                break;
        
        if(i1 == -1) // means array is like [4 3 2 1]
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        for(int i = i1+1; i < n; ++i)
            if(nums[i] > nums[i1]) // find number just larger than nums[i1], stored int i2
                i2 = i;
        
        swap(nums[i1], nums[i2]); // swap 
        reverse(nums.begin()+i1+1, nums.end()); // reverse from i1+1 to end
    }
};
