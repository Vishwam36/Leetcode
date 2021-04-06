// By Vishwam Shriram Mundada
// https://leetcode.com/problems/course-schedule/
// Simple cycle detection question

class Solution {
public:
    bool detectCycle(int source, vector<int> adj[], bool visited[], bool rec[])
    {
        if(rec[source])
            return true;
        
        if(visited[source])
            return false;
        
        rec[source] = 1;
        visited[source] = 1;
        
        for(int i = 0; i < adj[source].size(); ++i)
        {
            int child = adj[source][i];
            if(!visited[child] && detectCycle(child, adj, visited, rec))
                return true;
            
            if(rec[child])
                return true;
        }
        rec[source] = 0;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        bool ans = false;
        vector<int> adj[numCourses];
        
        for(int i = 0; i < prerequisites.size(); ++i)
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        
        bool visited[numCourses];
        bool rec[numCourses];
        for(int i = 0; i < numCourses; ++i)
        {
            rec[i] = 0;
            visited[i] = 0;
        }
        
        for(int i = 0; i < numCourses; ++i)
        {
            if(!ans && !visited[i])
            {
                ans = ans || detectCycle(i, adj, visited, rec);
            }
        }
        return !ans;
    }
};
