// By Vishwam Shriram Mundada
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/776/
// Easy

/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Example 2:
Input: nums = []
Output: []

Example 3:
Input: nums = [0]
Output: []

Constraints:
    0 <= nums.length <= 3000
    -105 <= nums[i] <= 105
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        set<vector<int> > ans;
        
        for(int i = 0; i < n; ++i)
        {
            int l = i+1, r = n-1;
            while(r > l)
            {
                if(nums[l] + nums[r] + nums[i] == 0)
                {
                    ans.insert({nums[i], nums[l], nums[r]});
                    ++l;
                }
                else if(nums[l] + nums[r] + nums[i] < 0)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }
        return vector<vector<int> >(ans.begin(), ans.end());
    }
};
