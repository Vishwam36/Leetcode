// By Vishwam Shriram Mundada
// https://leetcode.com/problems/maximize-score-after-n-operations/
// Good question

/*
You are given nums, an array of positive integers of size 2 * n. You must perform n operations on this array.

In the ith operation (1-indexed), you will:

Choose two elements, x and y.
Receive a score of i * gcd(x, y).
Remove x and y from nums.
Return the maximum score you can receive after performing n operations.

The function gcd(x, y) is the greatest common divisor of x and y.

Example 1:
Input: nums = [1,2]
Output: 1
Explanation: The optimal choice of operations is:
(1 * gcd(1, 2)) = 1

Example 2:
Input: nums = [3,4,6,8]
Output: 11
Explanation: The optimal choice of operations is:
(1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11

Example 3:
Input: nums = [1,2,3,4,5,6]
Output: 14
Explanation: The optimal choice of operations is:
(1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14

Constraints:
1 <= n <= 7
nums.length == 2 * n
1 <= nums[i] <= 106
*/

class Solution {
public:
    // in mask if bit = 1 then we have chosen that num else not
    unordered_map<int, int> m;
    
    int rec(vector<int>& nums, int mask, int op)
    {
        int n = nums.size();
        if(mask == (1 << n)-1) // mask is all ones of length n-1 i.e all selected
            return 0; // if all selected then no need to add anything
        
        if(m.find(mask) != m.end())
            return m[mask];
        
        int ans = 0;
        for(int i = 0; i < n; ++i)
            if(((mask) & (1 << i)) == 0) // if ith bit is unset
                for(int j = i+1; j < n; ++j)
                    if(((mask) & (1 << j)) == 0) // if jth bit is unset
                        ans = max(ans, op * __gcd(nums[i], nums[j]) + rec(nums, mask | (1 << i) | (1 << j), op+1));
        
        return m[mask] = ans;
    }
    
    int maxScore(vector<int>& nums) 
    {
        m.clear();
        return rec(nums, 0, 1);
    }
};
