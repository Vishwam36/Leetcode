// By Vishwam Shriram Mundada
// https://leetcode.com/problems/binary-tree-inorder-traversal/
// Easy

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
    vector<int> ans;
    
    void rec(TreeNode* root)
    {
        if(!root)
            return;
        
        rec(root->left);
        ans.push_back(root->val);
        rec(root->right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) 
    {
        rec(root);
        return ans;
    }
};
