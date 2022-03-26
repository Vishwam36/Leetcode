// By Vishwam Shriram Mundada
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/114/others/826/
// Good

/*
Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. 
Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that 
there must be at least n units of time between any two same tasks.

Return the least number of units of times that the CPU will take to finish all the given tasks.

Example 1:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: 
A -> B -> idle -> A -> B -> idle -> A -> B
There is at least 2 units of time between any two same tasks.

Example 2:
Input: tasks = ["A","A","A","B","B","B"], n = 0
Output: 6
Explanation: On this case any permutation of size 6 would work since n = 0.
["A","A","A","B","B","B"]
["A","B","A","B","A","B"]
["B","B","B","A","A","A"]
...
And so on.

Example 3:
Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
Output: 16
Explanation: 
One possible solution is
A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A

Constraints:
    1 <= task.length <= 10^4
    tasks[i] is upper-case English letter.
    The integer n is in the range [0, 100].
*/

// REF : https://www.youtube.com/watch?v=S6B7PY4c690&list=PLvcnKuMSuSe9SO8iX78JFtze-lRQPCReh&index=22

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        vector<int> f(26, 0);
        for(auto& ch : tasks)
            f[ch-'A']++;
        
        priority_queue<int> pq;
        for(int i = 0; i < 26; ++i)
            if(f[i])
                pq.push(f[i]);
        
        queue<pair<int, int>> q;
        int t = 0;
        
        while(!pq.empty() || !q.empty())
        {
            if(pq.empty())
            {
                pq.push(q.front().first);
                t = q.front().second;
                q.pop();
                continue;
            }
            
            int curr = pq.top(); pq.pop();
            t++;
            
            curr--;
            if(curr)
                q.push({curr, t+n});
            
            if(q.front().second == t)
            {
                pq.push(q.front().first);
                q.pop();
            }
        }
        
        return t;
    }
};
