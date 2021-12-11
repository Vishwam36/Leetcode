// By Vishwam Shriram Mundada
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/110/sorting-and-searching/800/
// Easy

/*
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Example 2:
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

Constraints:
    1 <= k <= nums.length <= 10^4
    -10^4 <= nums[i] <= 10^4
*/

// TC : O(n log(k))
// SC : O(k)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        multiset<int> s;
        
        for(auto num : nums)
        {
            s.insert(num);
            if(s.size() > k)
                s.erase(s.begin());
        }
        
        return *s.begin();
    }
};
