// By Vishwam Shriram Mundada
// https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/627/
// Easy

/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Example 1:
Input: root = [1,2,2,3,4,4,3]
Output: true

Example 2:
Input: root = [1,2,2,null,3,null,3]
Output: false

Constraints:
    The number of nodes in the tree is in the range [1, 1000].
    -100 <= Node.val <= 100

Follow up: Could you solve it both recursively and iteratively?
*/


class Solution {
public:
    bool rec(TreeNode* l, TreeNode* r)
    {
        if(!l && !r)
            return true;
        if(!l || !r)
            return false;
        if(l->val != r->val)
            return false;
        
        return rec(l->left, r->right) && rec(l->right, r->left);
    }
    
    bool isSymmetric(TreeNode* root) 
    {
        return rec(root->left, root->right);
    }
};
