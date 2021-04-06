// By Vishwam Shriram Mundada
// https://leetcode.com/problems/course-schedule-ii/
// Decent topological sort question

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int> ans;
        
        int indegree[numCourses];
        bool vis[numCourses];
        for(int i = 0; i < numCourses; ++i)
        {
            vis[i] = 0;
            indegree[i] = 0;
        }
        
        vector<int> adj[numCourses];
        for(int i = 0; i < prerequisites.size(); ++i)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; ++i)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
                vis[i] = 1;
            }
        }
        
        while(!q.empty())
        {
            int curr = q.front();
            ans.push_back(curr);
            q.pop();
            
            for(int i = 0; i < adj[curr].size(); ++i)
            {
                int child = adj[curr][i];
                indegree[child]--;
                
                if(indegree[child] == 0 && !vis[child])
                {
                    q.push(child);
                    vis[child] = 1;
                }
            }
        }
        
        if(ans.size() == numCourses)
            return ans;
        
        return {};
    }
};
