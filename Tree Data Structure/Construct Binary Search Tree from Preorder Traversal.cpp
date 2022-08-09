// By Vishwam Shriram Mundada
// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

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
    TreeNode* rec(int l, int r, vector<int>& pre)
    {
        if(l > r)
            return NULL;
        if(l == r)
            return new TreeNode(pre[l]);
        
        int i = l;
        while(i <= r && pre[i] <= pre[l])
            ++i;
        
        return new TreeNode(pre[l], rec(l+1, i-1, pre), rec(i, r, pre));
    }
    
    TreeNode* bstFromPreorder(vector<int>& pre)
    {
        return rec(0, pre.size()-1, pre);
    }
};
