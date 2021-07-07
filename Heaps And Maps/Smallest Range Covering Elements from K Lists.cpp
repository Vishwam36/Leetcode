// By Vishwam Shriram Mundada
// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
// Good question
// REF : https://www.youtube.com/watch?v=bWowdBPkidw&ab_channel=AdityaRajiv

/*
You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

Example 1:
Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].

Example 2:
Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]

Example 3:
Input: nums = [[10,10],[11,11]]
Output: [10,11]

Example 4:
Input: nums = [[10],[11]]
Output: [10,11]

Example 5:
Input: nums = [[1],[2],[3],[4],[5],[6],[7]]
Output: [1,7]

Constraints:
nums.length == k
1 <= k <= 3500
1 <= nums[i].length <= 50
-105 <= nums[i][j] <= 10^5
nums[i] is sorted in non-decreasing order.
*/

class Solution {
public:
    #define pp pair<int, pair<int, int> > // {num, {row, col}}
    
    vector<int> smallestRange(vector<vector<int>>& nums) 
    {
        int n = nums.size(), maxEle = INT_MIN, minEle, range = INT_MAX;
        
        vector<int> ans(2);
        priority_queue<pp, vector<pp>, greater<pp> > pq;
        
        for(int i = 0; i < n; ++i)
        {
            pq.push({nums[i][0], {i, 0}});
            maxEle = max(maxEle, nums[i][0]);
        }
        
        while(1)
        {
            minEle = pq.top().first;
            auto p = pq.top().second;
            int r = p.first;
            int c = p.second;
            pq.pop();
            
            if(range > maxEle - minEle)
            {
                range = maxEle - minEle;
                ans[0] = minEle;
                ans[1] = maxEle;
            }
            
            if(c == nums[r].size()-1)
                break;
            
            pq.push({nums[r][c+1], {r, c+1}});
            maxEle = max(maxEle, nums[r][c+1]);
        }
        
        return ans;
    }
};
