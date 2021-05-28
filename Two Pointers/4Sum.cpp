// By Vishwam Shriram Mundada
// https://leetcode.com/problems/4sum/
// Decent

/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
    0 <= a, b, c, d < n
    a, b, c, and d are distinct.
    nums[a] + nums[b] + nums[c] + nums[d] == target

You may return the answer in any order.

Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]

Constraints:
    1 <= nums.length <= 200
    -109 <= nums[i] <= 109
    -109 <= target <= 109
*/

// App 1 : 
// Using two pinters, reduce 4Sum->3Sum->2Sum and then use 2 pointers

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int> > ans;
        
        for(int i = 0; i <= n-4; ++i)
        {
            for(int j = i+1; j <= n-3; ++j)
            {
                int newTarget = target - (nums[i]+nums[j]);
                int l = j+1, r = n-1;
                
                while(l < r)
                {
                    if(nums[l]+nums[r] == newTarget)
                    {
                        ans.insert( {nums[i], nums[j], nums[l], nums[r]} );
                        --r;
                    }
                    else if(nums[l]+nums[r] < newTarget)
                        l++;
                    else
                        r--;
                }
            }
        }
        return vector<vector<int> > (ans.begin(), ans.end());
    }
};

// App 2 : 
// Using map

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int k) 
    {
        int n = arr.size();
        set<vector<int> > ans_set;
        
        map<int, vector<pair<int, int> > > m;
        for(int i = 0; i < n; ++i)
            for(int j = i+1; j < n; ++j)
                m[arr[i]+arr[j]].push_back({i, j});
        
        for(auto it = m.begin(); it != m.end(); ++it)
        {
            int sum1 = it->first;
            int sum2 = k-sum1;
            
            if(m.find(sum2) == m.end())
                continue;
            
            vector<pair<int, int> > v1 = m[sum1];
            vector<pair<int, int> > v2 = m[sum2];
            
            
            for(int i = 0; i < v1.size(); ++i)
            {
                for(int j = 0; j < v2.size(); ++j)
                {
                    int i1 = v1[i].first;
                    int j1 = v1[i].second;
                    int i2 = v2[j].first;
                    int j2 = v2[j].second;
                    
                    if(i1 == i2 || i1 == j2 || j1 == i2 || j1 == j2)
                        continue;
                    
                    vector<int> temp = {arr[i1], arr[j1], arr[i2], arr[j2]};
                    sort(temp.begin(), temp.end());
                    
                    ans_set.insert(temp);
                }
            }
        }
        return vector<vector<int> > (ans_set.begin(), ans_set.end());
    }
};
