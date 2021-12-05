// By Vishwam Shriram Mundada
// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/
// Good practice question

/*
You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing 
the value of the start node s, and a different integer destValue representing the value of the destination node t.

Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 
'L', 'R', and 'U'. Each letter indicates a specific direction:

    'L' means to go from a node to its left child node.
    'R' means to go from a node to its right child node.
    'U' means to go from a node to its parent node.

Return the step-by-step directions of the shortest path from node s to node t.

Example 1:
Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
Output: "UURL"
Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.

Example 2:
Input: root = [2,1], startValue = 2, destValue = 1
Output: "L"
Explanation: The shortest path is: 2 → 1.

Constraints:
    The number of nodes in the tree is n.
    2 <= n <= 10^5
    1 <= Node.val <= n
    All the values in the tree are unique.
    1 <= startValue, destValue <= n
    startValue != destValue
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
    TreeNode* findCommonParent(TreeNode* root, int s, int t)
    {
        if(!root)
            return NULL;
        
        if(root->val == s || root->val == t)
            return root;
        
        TreeNode* l = findCommonParent(root->left, s, t);
        TreeNode* r = findCommonParent(root->right, s, t);
        
        if(l && r)
            return root;
        if(l)
            return l;
        return r;
    }
    
    string s;
        
    bool path(TreeNode* root, int d)
    {
        if(!root)
            return false;
        
        if(root->val == d)
            return true;
        
        s.push_back('L');
        if(path(root->left, d))
            return true;
        s.pop_back();
        
        s.push_back('R');
        if(path(root->right, d))
            return true;
        s.pop_back();
        
        return false;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue)
    {
        TreeNode* commonParent = findCommonParent(root, startValue, destValue);
        
        bool p1 = path(commonParent, startValue);
        string s1 = s;
        s = "";
        bool p2 = path(commonParent, destValue);
        string s2 = s;
        
        s1 = string(s1.size(), 'U');
        
        return s1+s2;
    }
};
