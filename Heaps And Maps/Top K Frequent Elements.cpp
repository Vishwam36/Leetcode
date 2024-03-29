// By Vishwam Shriram Mundada
// https://leetcode.com/problems/top-k-frequent-elements/
// Easy

/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]

Constraints:
    1 <= nums.length <= 105
    k is in the range [1, the number of unique elements in the array].
    It is guaranteed that the answer is unique.

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        int n = nums.size();
        unordered_map<int, int> m;
        for(auto x : nums)
            m[x]++;
        
        vector<pair<int, int> > v;
        for(auto it : m)
            v.push_back({it.second, it.first});
        
        auto comp = [&m](int n1, int n2){
            return m[n1] > m[n2];
        };
        
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        for(auto it : m)
        {
            pq.push(it.first);
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<int> ans;
        while(pq.size() > 0)
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
