// By Vishwam Shriram Mundada
// https://leetcode.com/problems/closest-subsequence-sum/
// Good question, Meet in The Middle, Binary Search, Backtracking, Divide and Conquer

/*
You are given an integer array nums and an integer goal.
You want to choose a subsequence of nums such that the sum of its elements is the closest possible to goal. 
That is, if the sum of the subsequence's elements is sum, then you want to minimize the absolute difference abs(sum - goal).
Return the minimum possible value of abs(sum - goal).
Note that a subsequence of an array is an array formed by removing some elements (possibly all or none) of the original array.

Example 1:
Input: nums = [5,-7,3,5], goal = 6
Output: 0
Explanation: Choose the whole array as a subsequence, with a sum of 6.
This is equal to the goal, so the absolute difference is 0.

Example 2:
Input: nums = [7,-9,15,-2], goal = -5
Output: 1
Explanation: Choose the subsequence [7,-9,-2], with a sum of -4.
The absolute difference is abs(-4 - (-5)) = abs(1) = 1, which is the minimum.

Example 3:
Input: nums = [1,2,3], goal = -7
Output: 7

Constraints:
    1 <= nums.length <= 40
    -107 <= nums[i] <= 107
    -109 <= goal <= 109
*/

/*
Hint:
1. Divide the input array into two groups with similar sizes (N/2).
2. Compute a super sum array of size (2^N/2) for each group of input.
3. Sort the two super sum arrays (use set).
4. For each element in the first super sum array, run a binary search in second super sum array and find out the closest sum to goal.
*/

class Solution {
public:    
    void generate_sums(vector<int>& v, set<int>& s, int sum, int index)
    {
        s.insert(sum);
        
        for(int i = index; i < v.size(); ++i)
            generate_sums(v, s, sum+v[i], i+1);
    }
    
    int find_closest(int x, set<int>& s)
    {        
        auto it = s.lower_bound(x);
        int y1 = *it;
        
        if(it == s.begin())
            return y1;
        
        --it;
        int y2 = *it;
        
        return abs(y1-x) <= abs(y2-x) ? y1 : y2;
    }
    
    int minAbsDifference(vector<int>& nums, int goal) 
    {
        int n = nums.size(), pos = 0, neg = 0, ans = INT_MAX;
        
        if(n == 1)
            return min(abs(goal-nums[0]), abs(goal));
        
        for(auto num : nums)
        {
            pos += max(0, num);
            neg += min(0, num);
        }
        
        if(goal > pos || goal < neg)
            return min(abs(goal-pos), abs(goal-neg));
        
        vector<int> v1, v2;
        set<int> s1, s2;
        
        for(int i = 0; i < n/2; ++i)
            v1.push_back(nums[i]);
        
        for(int i = n/2; i < n; ++i)
            v2.push_back(nums[i]);
        
        generate_sums(v1, s1, 0, 0);
        generate_sums(v2, s2, 0, 0);
        
        for(auto x : s1)
        {
            int y = find_closest(goal-x, s2);
            ans = min(ans, abs(goal - (x+y)));
        }
        
        return ans;
    }
};
