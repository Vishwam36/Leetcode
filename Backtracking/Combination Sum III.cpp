// https://leetcode.com/problems/combination-sum-iii/description/
// Easy

class Solution {
public:
    vector<vector<int> > ans;

    void rec(int i, int sum, int k, int n, vector<int> &v)
    {
        if(k == 0)
        {
            if(sum == n)
                ans.push_back(v);
            return;
        }

        if(sum > n || i >= 10)
            return;

        v.push_back(i);
        rec(i+1, sum+i, k-1, n, v);
        v.pop_back();
        rec(i+1, sum, k, n, v);
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> v;
        rec(1, 0, k, n, v);
        return ans;
    }
};
