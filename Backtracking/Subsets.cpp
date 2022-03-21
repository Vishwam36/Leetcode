// By Vishwam Shriram Mundada
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/109/backtracking/796/
// Easy

/*
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]

Constraints:
    1 <= nums.length <= 10
    -10 <= nums[i] <= 10
    All the numbers of nums are unique.
*/

class Solution {
public:
    vector<vector<int> > ans;
    
    void rec(int idx, vector<int>& nums, vector<int> &v)
    {
        if(idx == nums.size())
        {
            ans.push_back(v);
            return;
        }
        
        rec(idx+1, nums, v);
        
        v.push_back(nums[idx]);
        rec(idx+1, nums, v);
        v.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<int> v;
        rec(0, nums, v);
        return ans;
    }
};
