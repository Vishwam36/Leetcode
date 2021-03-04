// By Vishwam Shriram Mundada
// https://leetcode.com/problems/validate-binary-search-tree/
// Easy but important

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

bool isBSTUtil(TreeNode* root, long minLimit, long maxLimit)
{
    if(root == NULL)
        return true;
    
    return (root -> val > minLimit 
           && root -> val < maxLimit
           && isBSTUtil(root -> left, minLimit, root -> val)
           && isBSTUtil(root -> right, root -> val, maxLimit));
}

class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
        return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
    }
};
