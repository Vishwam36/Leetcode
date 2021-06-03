// By Vishwam Shriram Mundada
// https://leetcode.com/problems/binary-tree-preorder-traversal/
// Iterative Approach is good
// REF : https://www.youtube.com/watch?v=12aMTS0L6WI&t=154s

// Recursive Approach 

class Solution {
public:
    vector<int> pre;
    
    void rec(TreeNode* root)
    {
        if(!root)
            return;
        
        pre.push_back(root->val);
        rec(root->left);
        rec(root->right);
    }
    
    vector<int> preorderTraversal(TreeNode* root) 
    {
        rec(root);
        return pre;
    }
};

// Iterative approach

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> pre;
        
        stack<pair<TreeNode*, int> > s;
        if(root)
            s.push({root, 1});
        
        while(!s.empty())
        {
            TreeNode* curr = s.top().first;
            int state = s.top().second;
            
            if(state == 1) // first time visited
            {
                pre.push_back(curr->val);
                s.top().second++;
                
                if(curr->left)
                    s.push({curr->left, 1});
            }
            else if(state == 2) // left part is visited
            {
                s.top().second++;
                
                if(curr->right)
                    s.push({curr->right, 1});
            }
            else // left right both visited
            {
                s.pop();
            }
        }
        
        return pre;
    }
};
