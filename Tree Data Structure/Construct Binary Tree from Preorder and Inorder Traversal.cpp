// By Vishwam Shriram Mundada
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/108/trees-and-graphs/788/
// Decent

/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, 
construct and return the binary tree.

Example 1:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: preorder = [-1], inorder = [-1]
Output: [-1]

Constraints:
    1 <= preorder.length <= 3000
    inorder.length == preorder.length
    -3000 <= preorder[i], inorder[i] <= 3000
    preorder and inorder consist of unique values.
    Each value of inorder also appears in preorder.
    preorder is guaranteed to be the preorder traversal of the tree.
    inorder is guaranteed to be the inorder traversal of the tree.
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
    TreeNode* rec(vector<int>& pre, vector<int>& in, int i1, int i2, int p1, int p2)
    {
        if(i2 < i1)
            return NULL;
        
        TreeNode* root = new TreeNode(pre[p1]);
        
        int idx = -1;
        for(int i = i1; i <= i2; ++i)
            if(in[i] == pre[p1])
            {
                idx = i;
                break;
            }
        
        int l = idx-i1; // length of left subtree
        int r = i2-idx; // length of right subtree
        root->left = rec(pre, in, i1, idx-1, p1+1, p1+l);
        root->right = rec(pre, in, idx+1, i2, p1+l+1, p2);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) 
    {
        return rec(pre, in, 0, in.size()-1, 0, pre.size()-1);
    }
};
