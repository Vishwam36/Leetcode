// By Vishwam Shriram Mundada
// https://leetcode.com/problems/valid-arrangement-of-pairs/
// Good, Euler path

/*
You are given a 0-indexed 2D integer array pairs where pairs[i] = [starti, endi]. An arrangement of pairs is valid if for every index i where 1 <= i < pairs.length,
we have endi-1 == starti.

Return any valid arrangement of pairs.

Note: The inputs will be generated such that there exists a valid arrangement of pairs.

Example 1:
Input: pairs = [[5,1],[4,5],[11,9],[9,4]]
Output: [[11,9],[9,4],[4,5],[5,1]]
Explanation:
This is a valid arrangement since endi-1 always equals starti.
end0 = 9 == 9 = start1 
end1 = 4 == 4 = start2
end2 = 5 == 5 = start3

Example 2:
Input: pairs = [[1,3],[3,2],[2,1]]
Output: [[1,3],[3,2],[2,1]]
Explanation:
This is a valid arrangement since endi-1 always equals starti.
end0 = 3 == 3 = start1
end1 = 2 == 2 = start2
The arrangements [[2,1],[1,3],[3,2]] and [[3,2],[2,1],[1,3]] are also valid.

Example 3:
Input: pairs = [[1,2],[1,3],[2,1]]
Output: [[1,2],[2,1],[1,3]]
Explanation:
This is a valid arrangement since endi-1 always equals starti.
end0 = 2 == 2 = start1
end1 = 1 == 1 = start2

Constraints:
    1 <= pairs.length <= 105
    pairs[i].length == 2
    0 <= starti, endi <= 109
    starti != endi
    No two pairs are exactly the same.
    There exists a valid arrangement of pairs.
*/

class Solution {
public:
    vector<vector<int> > ans;
    
    void dfs(int src, unordered_map<int, vector<int> > &adj)
    {
        while(adj[src].size() > 0)
        {
            int next = adj[src].back();
            adj[src].pop_back();
            
            dfs(next, adj);
            ans.push_back({src, next});
        }
    }
    
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs)
    {
        unordered_map<int, vector<int> > adj;
        unordered_map<int, int> in, out;
        
        for(auto p : pairs)
        {
            int u = p[0];
            int v = p[1];
            
            adj[u].push_back(v);
            
            in[v]++;
            out[u]++;
        }
        
        int start = -1;
        
        for(auto& it : adj)
        {
            int node = it.first;
            if(out[node] - in[node] == 1)
            {
                start = node;
                break;
            }
        }
        
        if(start == -1)
            start = pairs[0][0];
                
        dfs(start, adj);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
