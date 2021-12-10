// By Vishwam Shriram Mundada
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/112/design/812/
// Decent

/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, 
or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. 
You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, 
so please be creative and come up with different approaches yourself.

Example 1:
Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1]
Output: [1]

Example 4:
Input: root = [1,2]
Output: [1,2]

Constraints:
    The number of nodes in the tree is in the range [0, 104].
    -1000 <= Node.val <= 1000
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void tree_to_string(TreeNode* root, string &s)
    {
        if(!root)
        {
            s += "n ";
            return;
        }
        
        s += to_string(root->val);
        s += " ";
        tree_to_string(root->left, s);
        tree_to_string(root->right, s);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        string s;
        tree_to_string(root, s);
        return s;
    }
        
    TreeNode* string_to_tree(int &idx, string &s)
    {
        if(idx >= s.size()-1)
            return NULL;
        
        while(s[idx] == ' ')
            idx++;
        
        string num;
        while(s[idx] != ' ')
        {
            num.push_back(s[idx]);
            idx++;
        }
                
        if(num == "n")
            return NULL;
        
        TreeNode* newNode = new TreeNode(stoi(num));
        newNode->left = string_to_tree(idx, s);
        newNode->right = string_to_tree(idx, s);
        return newNode;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        int idx = 0;
        return string_to_tree(idx, data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
