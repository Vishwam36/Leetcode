// By Vishwam Shriram Mundada
// https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/631/
// Easy

/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

Example 1:
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:
Input: nums = [1,3]
Output: [3,1]
Explanation: [1,3] and [3,1] are both a height-balanced BSTs.

Constraints:
    1 <= nums.length <= 10^4
    -104 <= nums[i] <= 10^4
    nums is sorted in a strictly increasing order.
*/


class Solution {
public:
    TreeNode* rec(vector<int> &nums, int l, int r)
    {
        if(l > r)
            return NULL;
        
        int mid = (l+r)/2;
        TreeNode* temp = new TreeNode(nums[mid]);
        temp->left = rec(nums, l, mid-1);
        temp->right = rec(nums, mid+1, r);
        return temp;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return rec(nums, 0, nums.size()-1);
    }
};
