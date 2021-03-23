// By Vishwam Shriram Mundada
// https://leetcode.com/problems/queue-reconstruction-by-height/
// Good concept

bool cmp(vector<int> &v1, vector<int> &v2)
{
    if(v1[0] == v2[0])
        return v1[1] < v2[1];
    
    return v1[0] > v2[0];
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        vector<vector<int> > ans;
        sort(people.begin(), people.end(), cmp);
        
        for(int i = 0; i < people.size(); ++i)
        {
            ans.insert(ans.begin() + people[i][1], people[i]);
        }
        
        return ans;
    }
};
