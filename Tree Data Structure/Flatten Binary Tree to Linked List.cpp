// By Vishwam Shriram Mundada
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
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
    TreeNode* rec(TreeNode* root)
    {
        if(!root)
            return root;
        
        TreeNode* r = root->right;
        root->right = rec(root->left);
        root->left = NULL;
        
        auto t = root;
        while(t->right)
            t = t->right;
        
        t->right = rec(r);
        return root;
    }
    
    void flatten(TreeNode* root)
    {
        root = rec(root);
    }
};
