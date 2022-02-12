// By Vishwam Shriram Mundada
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/123/math/872/
// Decent

/*
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

Example 1:
Input: nums = [10,2]
Output: "210"

Example 2:
Input: nums = [3,30,34,5,9]
Output: "9534330"

Constraints:
    1 <= nums.length <= 100
    0 <= nums[i] <= 10^9
*/

class Solution {
public:
    string largestNumber(vector<int>& nums)
    {
        int n = nums.size();
        vector<string> vs(n);
        for(int i = 0; i < n; ++i)
            vs[i] = to_string(nums[i]);
        
        sort(vs.begin(), vs.end(), [](string &a, string &b){
            return a+b > b+a;
        });
        
        string ans;
        int i = 0;
        while(i < n-1 && vs[i] == "0")
            ++i;
        
        while(i < n)
            ans += vs[i++];
        
        return ans;
    }
};
