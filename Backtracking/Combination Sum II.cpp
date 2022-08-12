// By Vishwam Shriram Mundada
// https://leetcode.com/problems/combination-sum-ii/
// REF : https://www.youtube.com/watch?v=G1fRTGRxXU8

class Solution {
public:
    vector<vector<int> > ans;
    set<vector<int> > vis;
    
    void rec(int idx, vector<int>& v, int sum, vector<int> &temp)
    {   
        if(sum == 0)
            ans.push_back(temp);
        if(sum < 0)
            return;
        
        for(int i = idx; i < v.size(); ++i)
        {
            if(i > idx && v[i] == v[i-1])
                continue;
                        
            temp.push_back(v[i]);
            rec(i+1, v, sum-v[i], temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& v, int target) 
    {
        sort(v.begin(), v.end());
        vector<int> temp;
        rec(0, v, target, temp);
        return ans;
    }
};
