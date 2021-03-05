// By Vishwam Shriram Mundada
// https://leetcode.com/problems/diameter-of-binary-tree/
// Decent, important

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

int height(TreeNode* root)
{
    if(root == NULL)
        return 0;
    
    return max(height(root -> left), height(root -> right)) + 1;
}

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        int lHeight = height(root -> left);
        int rHeight = height(root -> right);
        
        int dLeft = diameterOfBinaryTree(root -> left);
        int dRight = diameterOfBinaryTree(root -> right);
        
        return max(lHeight + rHeight, max(dLeft, dRight));
    }
};
