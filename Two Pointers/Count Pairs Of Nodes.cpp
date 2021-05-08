// By Vishwam Shriram Mundada
// https://leetcode.com/problems/count-pairs-of-nodes/
// Good question, i think its more of two pointers than just graph
// Ref : https://www.youtube.com/watch?v=9pAVTzVYnPc&ab_channel=HappyCoding

/*
You are given an undirected graph represented by an integer n, which is the number of nodes, and edges, where edges[i] = [ui, vi] 
which indicates that there is an undirected edge between ui and vi. You are also given an integer array queries.

The answer to the jth query is the number of pairs of nodes (a, b) that satisfy the following conditions:

a < b
cnt is strictly greater than queries[j], where cnt is the number of edges incident to a or b.
Return an array answers such that answers.length == queries.length and answers[j] is the answer of the jth query.

Note that there can be repeated edges.

Example 1:
Input: n = 4, edges = [[1,2],[2,4],[1,3],[2,3],[2,1]], queries = [2,3]
Output: [6,5]
Explanation: The number of edges incident to at least one of each pair is shown above.

Example 2:
Input: n = 5, edges = [[1,5],[1,5],[3,4],[2,5],[1,3],[5,1],[2,3],[2,5]], queries = [1,2,3,4,5]
Output: [10,10,9,8,6]

Constraints:
2 <= n <= 2 * 104
1 <= edges.length <= 105
1 <= ui, vi <= n
ui != vi
1 <= queries.length <= 20
0 <= queries[j] < edges.length
*/

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) 
    {
        vector<int> ans(queries.size());
        vector<int> degree(n, 0), sortedDegree(n, 0);
        map<pair<int, int>, int> edgeFreq;
        for(int i = 0; i < edges.size(); ++i)
        {
            int x = edges[i][0]-1;
            int y = edges[i][1]-1;
            int u = min(x,y);
            int v = max(x,y);
            degree[u]++;
            degree[v]++;
            sortedDegree[u]++;
            sortedDegree[v]++;
            
            edgeFreq[{u, v}]++;
        }
        
        sort(sortedDegree.begin(), sortedDegree.end());
        
        for(int i = 0; i < queries.size(); ++i)
        {
            int val = queries[i];
            int l = 0, r = n-1, cnt = 0;
            
            for(int l = 0; l < n; ++l)
            {
                while(r > l && sortedDegree[l] + sortedDegree[r] > val)
                    r -= 1;
                
                if(l < r)
                    cnt += n-r-1;
                else
                    cnt += n-l-1;
            }
            
            for(auto& [key, w] : edgeFreq)
            {
                int u = key.first;
                int v = key.second;
                
                if(degree[u] + degree[v] > val && degree[u] + degree[v] - w <= val)
                    cnt -= 1;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};
