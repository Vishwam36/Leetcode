// By Vishwam Shriram Mundada
// https://leetcode.com/problems/combination-sum/
// Easy

void rec(vector<int> &v, vector<vector<int> > &ans, vector<int> temp, int target, int tempSum, int index)
{
    if(tempSum == target)
    {
        ans.push_back(temp);
        return;
    }
    
    if(index >= v.size() || tempSum > target)
    {
        return;
    }
    
    for(int i = index; i < v.size(); ++i)
    {
        temp.push_back(v[i]);
        rec(v, ans, temp, target, tempSum + v[i], i); // iterate for same index again because we can have same number multiple times
        temp.pop_back();
    }
}

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int> > ans;
        vector<int> temp;
        rec(candidates, ans, temp, target, 0, 0);
        return ans;
    }
};
