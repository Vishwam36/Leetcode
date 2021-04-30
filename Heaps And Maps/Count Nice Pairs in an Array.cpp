// By Vishwam Shriram Mundada
// https://leetcode.com/problems/count-nice-pairs-in-an-array/
// Easy, just a little trick
/*
You are given an array nums that consists of non-negative integers. Let us define rev(x) as the reverse of the non-negative integer x. For example, rev(123) = 321, and rev(120) = 21. A pair of indices (i, j) is nice if it satisfies all of the following conditions:

0 <= i < j < nums.length
nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
Return the number of nice pairs of indices. Since that number can be too large, return it modulo 109 + 7.

Example 1:
Input: nums = [42,11,1,97]
Output: 2
Explanation: The two pairs are:
 - (0,3) : 42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121.
 - (1,2) : 11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12.
 
Example 2:
Input: nums = [13,10,35,24,76]
Output: 4

Constraints:
1 <= nums.length <= 105
0 <= nums[i] <= 109
*/

/*
nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
==> nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])

difference is same 
*/

class Solution {
public:
    const int MOD = 1000000007;
    
    int rev(int n)
    {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        return stoi(s);
    }
    
    long long nc2(long long n)
    {
        return (n*(n-1))/2;
    }
    
    int countNicePairs(vector<int>& nums) 
    {
        long long ans = 0;
        unordered_map<int, int> m;
        
        for(int i = 0; i < nums.size(); ++i)
        {
            int diff = nums[i] - rev(nums[i]);
            m[diff]++;
        }
        
        for(auto it = m.begin(); it != m.end(); ++it)
        {
            if(it -> second > 1)
            {
                ans += nc2(it -> second);
                ans %= MOD;
            }
        }
        return ans;
    }
};
