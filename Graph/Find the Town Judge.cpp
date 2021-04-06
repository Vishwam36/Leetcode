// By Vishwam Shriram Mundada
// https://leetcode.com/problems/find-the-town-judge/
// Easy

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        int judge = -1;
        int indegree[n+1];
        int outdegree[n+1];
        
        for(int i = 0; i <= n; ++i)
        {
            outdegree[i] = 0;
            indegree[i] = 0;
        }
        
        for(int i = 0; i < trust.size(); ++i)
        {
            indegree[trust[i][1]]++;
            outdegree[trust[i][0]]++;
        }
        
        for(int i = 1; i <= n; ++i)
        {
            if(indegree[i] == n-1 && judge == -1)
                judge = i;
            
            else if(indegree[i] == n-1)
                return -1;
        }
        
        if(judge != -1 && outdegree[judge] > 0)
            return -1;
        
        return judge;
    }
};
