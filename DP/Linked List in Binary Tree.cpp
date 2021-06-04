// By Vishwam Shriram Mundada
// https://leetcode.com/problems/linked-list-in-binary-tree/
// Decent

/*
Given a binary tree root and a linked list with head as the first node. 

Return True if all the elements in the linked list starting from the head correspond to some downward path connected in the binary tree otherwise return False.

In this context downward path means a path that starts at some node and goes downwards.

Example 1:
Input: head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true
Explanation: Nodes in blue form a subpath in the binary Tree.  

Example 2:
Input: head = [1,4,2,6], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true

Example 3:
Input: head = [1,4,2,6,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: false
Explanation: There is no path in the binary tree that contains all the elements of the linked list from head.

Constraints:
    The number of nodes in the tree will be in the range [1, 2500].
    The number of nodes in the list will be in the range [1, 100].
    1 <= Node.val <= 100 for each node in the linked list and binary tree.
*/

class Solution {
public:
    ListNode* globalHead;    
    map<pair<ListNode*, TreeNode*>, bool> m;
    
    bool rec(ListNode* head, TreeNode* root, int n1, int n2)
    {
        if(head == NULL)
            return true;
        
        if(root == NULL)
            return false;
        
        if(m.find({head, root}) != m.end())
            return m[{head, root}];
        
        bool match = false;
        bool mismatch = false;
        
        if(root->val == head->val)
            match = rec(head->next, root->left, n1+1, n2+1) || rec(head->next, root->right, n1+1, n2+1);
        
        mismatch = rec(globalHead, root->left, n1+1, 0) || rec(globalHead, root->right, n1+1, 0);
        
        return m[{head, root}] = match || mismatch;
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) 
    {
        globalHead = head;
        return rec(head, root, 0, 0);
    }
};
