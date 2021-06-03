// By Vishwam Shriram Mundada
// https://leetcode.com/problems/binary-tree-postorder-traversal/
// Iterative approach good
// REF : https://www.youtube.com/watch?v=12aMTS0L6WI&t=154s

// Recursive approach

class Solution {
public:
    vector<int> post;
    
    void rec(TreeNode* root)
    {
        if(!root)
            return;
        
        rec(root->left);
        rec(root->right);
        post.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) 
    {
        rec(root);
        return post;
    }
};

// Iterative approach

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> post;
        
        stack<pair<TreeNode*, int> > s;
        if(root)
            s.push({root, 1});
        
        while(!s.empty())
        {
            TreeNode* curr = s.top().first;
            int state = s.top().second;
            
            if(state == 1) // first visited
            {
                s.top().second++;
                
                if(curr->left)
                    s.push({curr->left, 1});
            }
            else if(state == 2) // left part visited
            {
                s.top().second++;
                
                if(curr->right)
                    s.push({curr->right, 1});
            }
            else // both left right visited
            {
                post.push_back(curr->val);
                s.pop();
            }
        }
        return post;
    }
};
