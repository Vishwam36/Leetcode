// By Vishwam Shriram Mundada
// https://leetcode.com/problems/all-paths-from-source-to-target/
// Easy

void rec(vector<vector<int> > &ans, vector<vector<int>>& graph, vector<int> &temp, int index)
{
    if(temp.size() > 0)
    {
        if(temp.back() == graph.size()-1)
        {
            ans.push_back(temp);
            return;
        }
    }
    
    for(int i = 0; i < graph[index].size(); ++i)
    {
        temp.push_back(graph[index][i]);
        rec(ans, graph, temp, graph[index][i]);
        temp.pop_back();
    }
}

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<vector<int> > ans;
        vector<int> temp({0});
        rec(ans, graph, temp, 0);
        return ans;
    }
};
