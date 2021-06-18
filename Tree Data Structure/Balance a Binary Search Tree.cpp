// Vishwam Shriram Mundada
// https://leetcode.com/problems/balance-a-binary-search-tree/
// Easy

/*
Given a binary search tree, return a balanced binary search tree with the same node values.

A binary search tree is balanced if and only if the depth of the two subtrees of every node never differ by more than 1.

If there is more than one answer, return any of them.

Example 1:
Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2,null,null] is also correct.

Constraints:
    The number of nodes in the tree is between 1 and 10^4.
    The tree nodes will have distinct values between 1 and 10^5.
*/

 */
class Solution {
public:
    vector<int> in;
    
    void rec(TreeNode *root)
    {
        if(!root)
            return;
        
        rec(root->left);
        in.push_back(root->val);
        rec(root->right);
    }
    
    TreeNode* make(int l, int r)
    {
        if(l > r)
            return NULL;
        
        int mid = (l+r)/2;
        
        TreeNode* root = new TreeNode(in[mid]);
        
        root->left = make(l, mid-1);
        root->right = make(mid+1, r);
        
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) 
    {
        rec(root);
        return make(0, in.size()-1);
    }
};
