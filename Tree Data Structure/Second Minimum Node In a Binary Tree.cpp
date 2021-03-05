// By vishwam Shriram Mundada
// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/
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

long minVal = LLONG_MAX;
long secondMin = LLONG_MAX;

void findMin(TreeNode* root)
{
    if(root == NULL)
        return;
    
    minVal = min(minVal, (long)root -> val);
    findMin(root -> left);
    findMin(root -> right);
}

void findSecondMin(TreeNode* root)
{
    if(root == NULL)
        return;
    
    if(root -> val > minVal && root -> val < secondMin)
        secondMin = root -> val;
    
    findSecondMin(root -> left);
    findSecondMin(root -> right);
}

class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if(root == NULL || (root -> left == NULL && root -> right == NULL))
            return -1;
        
        minVal = LLONG_MAX;
        secondMin = LLONG_MAX;
        
        findMin(root);
        findSecondMin(root);
        
        if(secondMin == LLONG_MAX)
            return -1;
        
        return secondMin;
    }
};
