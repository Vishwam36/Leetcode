// By Vishwam Shriram Mundada
// https://leetcode.com/problems/course-schedule/
// Easy, both BFS and DFS

// App 1 : DFS : Detect cycle

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


// App 2 : BFS : Indegree

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) 
    {
        vector<int> adj[n];
        vector<int> in(n, 0);
        for(auto v : pre)
        {
            adj[v[0]].push_back(v[1]);
            in[v[1]]++;
        }
        
        int vis = 0;
        queue<int> q;
        for(int i = 0; i < n; ++i)
            if(in[i] == 0)
            {
                vis++;
                q.push(i);
            }
        
        while(!q.empty())
        {
            int curr = q.front(); q.pop();
            
            for(int i = 0; i < adj[curr].size(); ++i)
            {
                int next = adj[curr][i];
                in[next]--;
                
                if(in[next] == 0)
                {
                    q.push(next);
                    vis++;
                }
            }
        }
        
        return vis == n;
    }
};
