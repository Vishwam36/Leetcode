// By Vishwam Shriram Mundada
// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
// Decent

/*
Given a binary tree root. Split the binary tree into two subtrees by removing 1 edge such that the product of the sums of the subtrees are maximized.

Since the answer may be too large, return it modulo 10^9 + 7.

Example 1:
Input: root = [1,2,3,4,5,6]
Output: 110
Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)

Example 2:
Input: root = [1,null,2,3,4,null,null,5,6]
Output: 90
Explanation:  Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)

Example 3:
Input: root = [2,3,9,10,7,8,6,5,4,11,1]
Output: 1025

Example 4:
Input: root = [1,1]
Output: 1

Constraints:
    Each tree has at most 50000 nodes and at least 2 nodes.
    Each node's value is between [1, 10000].
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
    long long ans = 0;
    int MOD = 1000000007;
    long long total = 0;
    
    long long find_total(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        long long res = root->val;
        res += find_total(root->left);
        res += find_total(root->right);
        
        return res;
    }
    
    long long rec(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        long long sl = rec(root->left); // sum of left subtree
        long long sr = rec(root->right); // sum of right subtree
        long long whole = sl+sr+root->val; // left + right + current
        
        ans = max(ans, (sl)*(total-sl));
        ans = max(ans, (sr)*(total-sr));
        ans = max(ans, (whole)*(total-whole));
        
        return sl+sr+root->val;
    }
    
    int maxProduct(TreeNode* root) 
    {
        total = find_total(root); // total sum of whole tree
        rec(root);
        return ans % MOD;
    }
};
