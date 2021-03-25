// By Vishwam Shriram Mundada
// https://leetcode.com/problems/course-schedule-iii/
// Good question

class Solution {
public:
    static bool cmp(vector<int> &v1, vector<int> &v2)
    {
        return v1[1] < v2[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) 
    {
        sort(courses.begin(), courses.end(), cmp);
        
        int time = 0;
        priority_queue<int> pq;
        
        for(int i = 0; i < courses.size(); ++i)
        {
            if(time + courses[i][0] <= courses[i][1])
            {
                pq.push(courses[i][0]);
                time += courses[i][0];
            }
            else if(!pq.empty() && courses[i][0] < pq.top())
            {
                time -= pq.top();
                pq.pop();
                time += courses[i][0];
                pq.push(courses[i][0]);
            }
        }
        return pq.size();
    }
};
