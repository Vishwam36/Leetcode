// By Vishwam Shriram Mundada
// https://leetcode.com/problems/delete-node-in-a-bst/
// Decent, important

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

int findMin(TreeNode* root)
{
    while(root -> left != NULL)
        root = root -> left;
    
    return root -> val;
}

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(root == NULL)
            return root;
        
        if(key < root -> val)
            root -> left = deleteNode(root -> left, key);
        
        else if(key > root -> val)
            root -> right = deleteNode(root -> right, key);
        
        else // found the node to be deleted
        {
            if(root -> left == NULL && root -> right == NULL)
            {
                root = NULL;
                return root;
            }
            else if(root -> left == NULL)
            {
                TreeNode* temp = root;
                root = root -> right;
                delete temp;
                return root;
            }
            else if(root -> right == NULL)
            {
                TreeNode* temp = root;
                root = root -> left;
                delete temp;
                return root;
            }
            else
            {
                int rightMin = findMin(root -> right);
                root -> val = rightMin;
                root -> right = deleteNode(root -> right, rightMin);
            }
        }
        return root;
    }
};
