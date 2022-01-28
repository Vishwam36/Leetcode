// By Vishwam Shriram Mundada
// https://www.lintcode.com/problem/854/
// Good question

/*
Given a binary tree where every node has a unique value, and a target key k.

Find the value of the nearest leaf node to target k in the tree. If there are multiple cases, you should follow these priorities:

    The leaf node is in the left subtree of the node with k;
    The leaf node is in the right subtree of the node with k;
    The leaf node is not in the subtree of the node with k.

Example 1:
Input: {1, 3, 2}, k = 1
Output: 3
Explanation:

    1
   / \
  3   2

Example 2:
Input: {1}, k = 1
Output: 1
*/


// REF : https://www.youtube.com/watch?v=E2MncxV_v_g

class Solution {
public:
    vector<int> v;
    vector<int> leaf;

    // first value = minimum distance from leaf node in left or right branch going downwards
    // second value = value of node whose distance is in first value
    pair<int, int> rec(TreeNode* root)
    {
        if(!root)
            return {10000000, -1};
        
        pair<int, int> p;
        auto q1 = rec(root->left);
        auto q2 = rec(root->right);

        if(!root->left && !root->right)
            p = {0, root->val};
        
        else if(!root->left)
            p = {q2.first+1, q2.second};
        
        else if(!root->right)
            p = {q1.first+1, q1.second};
        
        else
            if(q1.first <= q2.first)
                p = {q1.first+1, q1.second};
            else
                p = {q2.first+1, q2.second};

        v[root->val] = p.first;
        leaf[root->val] = p.second;
        return p;
    }

    bool f = 0;
    int ansDist = INT_MAX, ans;
    int x = 0;

    void rec2(TreeNode* root, int k)
    {
        if(!root)
            return;

        if(root->val == k || f == 1)
        {
            f = 1;
            if(ansDist > v[root->val] + x)
            {
                ansDist = v[root->val] + x;
                ans = leaf[root->val];
            }
            x++;
        }
        else
        {
            rec2(root->left, k);
            rec2(root->right, k);
        }
    }

    int findClosestLeaf(TreeNode * root, int k) 
    {
        v = vector<int>(1001, 0);
        leaf = vector<int>(1001, 0);
        rec(root);
        rec2(root, k);
    
        return ans;
    }
};
