// By Vishwam Shriram Mundada
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/114/others/824/
// Decent

/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2

Constraints:
    n == nums.length
    1 <= n <= 5 * 104
    -2^31 <= nums[i] <= 2^31 - 1

Follow-up: Could you solve the problem in linear time and in O(1) space?
*/


class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int n = nums.size();
        int count = 0;
        int ans;
        
        for(auto num : nums)
        {
            if(count == 0)
            {
                ans = num;
                count++;
            }
            else
            {
                if(num == ans)
                    count++;
                else
                    count--;
            }
        }
        return ans;
    }
};
