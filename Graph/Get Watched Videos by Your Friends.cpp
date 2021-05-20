// By Vishwam Shriram Mundada
// https://leetcode.com/problems/get-watched-videos-by-your-friends/
// Decent, lengthy implementation

/*
There are n people, each person has a unique id between 0 and n-1. Given the arrays watchedVideos and friends, where watchedVideos[i] 
and friends[i] contain the list of watched videos and the list of friends respectively for the person with id = i.

Level 1 of videos are all watched videos by your friends, level 2 of videos are all watched videos by the friends of your friends and so on. 
In general, the level k of videos are all watched videos by people with the shortest path exactly equal to k with you. 

Given your id and the level of videos, return the list of videos ordered by their frequencies (increasing). 
For videos with the same frequency order them alphabetically from least to greatest. 

Example 1:
Input: watchedVideos = [["A","B"],["C"],["B","C"],["D"]], friends = [[1,2],[0,3],[0,3],[1,2]], id = 0, level = 1
Output: ["B","C"] 
Explanation: 
You have id = 0 (green color in the figure) and your friends are (yellow color in the figure):
Person with id = 1 -> watchedVideos = ["C"] 
Person with id = 2 -> watchedVideos = ["B","C"] 
The frequencies of watchedVideos by your friends are: 
B -> 1 
C -> 2

Example 2:
Input: watchedVideos = [["A","B"],["C"],["B","C"],["D"]], friends = [[1,2],[0,3],[0,3],[1,2]], id = 0, level = 2
Output: ["D"]
Explanation: 
You have id = 0 (green color in the figure) and the only friend of your friends is the person with id = 3 (yellow color in the figure).

Constraints:
    n == watchedVideos.length == friends.length
    2 <= n <= 100
    1 <= watchedVideos[i].length <= 100
    1 <= watchedVideos[i][j].length <= 8
    0 <= friends[i].length < n
    0 <= friends[i][j] < n
    0 <= id < n
    1 <= level < n
    if friends[i] contains j, then friends[j] contains i
*/

class Solution {
public:
    int n;
    
    vector<int> bfs(vector<int> adj[], int id, int k)
    {
        vector<int> vis(n, 0);
        
        queue<int> q;
        q.push(id);
        vis[id] = 1;
        
        int level = 0;
        while(!q.empty() && level < k)
        {
            int len = q.size();
            for(int i = 0; i < len; ++i)
            {
                int curr = q.front();
                q.pop();
                
                for(int i = 0; i < adj[curr].size(); ++i)
                {
                    int child = adj[curr][i];
                    if(vis[child])
                        continue;
                    
                    q.push(child);
                    vis[child] = 1;
                }
            }
            level++;
        }
        
        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
    
    static bool cmp(pair<string, int> &a, pair<string, int> &b)
    {
        if(a.second == b.second)
            return a.first < b.first;
        
        return a.second < b.second;
    }
    
    void getAns(vector<string> &ans, map<string, int> &m)
    {
        vector<pair<string, int> > v;
        for(auto it = m.begin(); it != m.end(); ++it)
            v.push_back({it -> first, it -> second});
        
        sort(v.begin(), v.end(), cmp);
        
        for(auto i : v)
            ans.push_back(i.first);
    }
    
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) 
    {
        n = friends.size();
        vector<int> adj[n];
        
        for(int idx = 0; idx < friends.size(); ++idx)
        {
            vector<int> v = friends[idx];
            for(int i = 0; i < v.size(); ++i)
                adj[idx].push_back(v[i]);
        }
        
        vector<int> level_k_friends = bfs(adj, id, level);
        map<string, int> m;
        for(int i = 0; i < level_k_friends.size(); ++i)
        {
            int f = level_k_friends[i];
            
            vector<string> vs = watchedVideos[f];
            for(auto str : vs)
                m[str]++;
        }
        vector<string> ans;
        getAns(ans, m);
        return ans;
    }
};
