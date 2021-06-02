// By Vishwam Shriram Mundada
// https://leetcode.com/problems/validate-binary-tree-nodes/
// Easy

/*
You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], 
return true if and only if all the given nodes form exactly one valid binary tree.

If node i has no left child then leftChild[i] will equal -1, similarly for the right child.

Note that the nodes have no values and that we only use the node numbers in this problem.

Example 1:
Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
Output: true

Example 2:
Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
Output: false

Example 3:
Input: n = 2, leftChild = [1,0], rightChild = [-1,-1]
Output: false

Example 4:
Input: n = 6, leftChild = [1,-1,-1,4,-1,-1], rightChild = [2,-1,-1,5,-1,-1]
Output: false

Constraints:
    1 <= n <= 104
    leftChild.length == rightChild.length == n
    -1 <= leftChild[i], rightChild[i] <= n - 1
*/

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) 
    {
        vector<int> in(n, 0); // indegree
        for(int i = 0; i < n; ++i)
        {
            if(leftChild[i] != -1)
                in[leftChild[i]]++;
            
            if(rightChild[i] != -1)
                in[rightChild[i]]++;
        }
        
        int root = -1, cnt = 0; // cnt stores no. of nodes except root
        for(int i = 0; i < n; ++i)
        {
            if(in[i] == 1)
                cnt++;
            
            if(in[i] > 1)
                return false;
            
            if(in[i] == 0 && root != -1)
                return false;
            
            else if(in[i] == 0 && root == -1)
                root = i;
        }
        
        if(root == -1 || cnt != n-1)
            return false;
        
        vector<bool> vis(n, false);
        
        queue<int> q;
        q.push(root);
        vis[root] = 1;
        int cntVis = 1;
        
        while(!q.empty())
        {
            int curr = q.front(); q.pop();
            
            int lc = leftChild[curr];
            int rc = rightChild[curr];
            
            if(lc != -1)
            {
                if(vis[lc])
                    return false;
                
                q.push(lc);
                vis[lc] = 1;
                cntVis++;
            }
            if(rc != -1)
            {
                if(vis[rc])
                    return false;
                
                q.push(rc);
                vis[rc] = 1;
                cntVis++;
            }
        }
        
        return cntVis == n; // whether all nodes are visited
    }
};
