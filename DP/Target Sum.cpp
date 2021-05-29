// By Vishwam Shriram Mundada
// https://leetcode.com/problems/target-sum/
// Decent

/*
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

    For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".

Return the number of different expressions that you can build, which evaluates to target.

Example 1:
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

Example 2:
Input: nums = [1], target = 1
Output: 1

Constraints:
    1 <= nums.length <= 20
    0 <= nums[i] <= 1000
    0 <= sum(nums[i]) <= 1000
    -1000 <= target <= 1000
*/

/*
we have to assign + and -
=> devide array into 2 subsets(s1, s2) s.t s1 has all +ve elements and s2 has all -ve elements
=> sum(s1) + sum(s2) = target
=> sum(s1) - sum(-s2) = target
=> s2 contains all -ve elements so, -s2 has all +ve(original elements which we have in nums)
=> sum(s1) - sum({nums - s1}) = target
=> now problem is devide nums into 2 subsets s.t their difference = target
=> sum(s1) - sum(s2) = target
=> sum(s1) + sum(s2) = total
=> sum(s1) = (target + total) / 2
=> subset sum problem
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int total = 0, n = nums.size();
        for(int num : nums)
            total += num;
        
        int sum = total + target;
        if(target > total || sum % 2 != 0)
            return 0;
        
        sum = sum/2;
        
        int dp[n+1][sum+1];
        for(int i = 0; i <= n; ++i)
            for(int j = 0; j <= sum; ++j)
                if(j == 0)
                    dp[i][j] = 1;
                else if(i == 0)
                    dp[i][j] = 0;
        
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 0; j <= sum; ++j) // notice that we have started from j = 0, for unserstanding consider case: nums = [0,0,0,0,0,0,0,0,1] target = 1

            {
                int include = 0;
                int not_include = dp[i-1][j];
                
                if(j - nums[i-1] >= 0)
                    include = dp[i-1][j-nums[i-1]];
                
                dp[i][j] = include + not_include;
            }
        }
        
        return dp[n][sum];
    }
};
