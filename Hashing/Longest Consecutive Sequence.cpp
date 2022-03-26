// By Vishwam Shriram Mundada
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/833/
// Decent

/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Constraints:
    0 <= nums.length <= 105
    -10^9 <= nums[i] <= 10^9
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        
        for(auto& num : nums)
            if(s.find(num-1) == s.end())
            {
                int l = 1, x = num+1;
                while(s.find(x) != s.end() && l++)
                    x++;
                ans = max(ans, l);
            }
        
        return ans;
    }
};
