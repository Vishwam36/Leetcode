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

// App 1 : Recursive

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

// App 2 : Stack approach

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        
        stack<TreeNode*> s;
        TreeNode* curr = root;
        
        while(!s.empty() || curr != NULL)
        {
            if(curr)
            {
                s.push(curr);
                curr = curr->left;
            }
            else
            {
                curr = s.top();
                s.pop();
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        return ans;
    }
};
