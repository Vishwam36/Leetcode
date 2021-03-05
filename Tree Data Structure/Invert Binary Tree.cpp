// By Vishwam shriram Mundada
// https://leetcode.com/problems/invert-binary-tree/
// Easy
/*
Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/

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
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return root;

        TreeNode* temp = root -> left;
        root -> left = root -> right;
        root -> right = temp;
        
        root -> left =  invertTree(root -> left);
        root -> right = invertTree(root -> right);
        
        return root;
    }
};
