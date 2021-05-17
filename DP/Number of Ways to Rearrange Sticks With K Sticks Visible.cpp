// By Vishwam shriram Mundada
// https://leetcode.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible/
// Easy as compared to other DP, Rec -> Memoization

/*
There are n uniquely-sized sticks whose lengths are integers from 1 to n. 
You want to arrange the sticks such that exactly k sticks are visible from the left. 
A stick is visible from the left if there are no longer sticks to the left of it.

For example, if the sticks are arranged [1,3,2,5,4], then the sticks with lengths 1, 3, and 5 are visible from the left.

Given n and k, return the number of such arrangements. Since the answer may be large, return it modulo 109 + 7.

Example 1:
Input: n = 3, k = 2
Output: 3
Explanation: [1,3,2], [2,3,1], and [2,1,3] are the only arrangements such that exactly 2 sticks are visible.
The visible sticks are underlined.

Example 2:
Input: n = 5, k = 5
Output: 1
Explanation: [1,2,3,4,5] is the only arrangement such that all 5 sticks are visible.
The visible sticks are underlined.

Example 3:
Input: n = 20, k = 11
Output: 647427950
Explanation: There are 647427950 (mod 109 + 7) ways to rearrange the sticks such that exactly 11 sticks are visible.

Constraints:
    1 <= n <= 1000
    1 <= k <= n
*/

/*
way to think about this problem is to assign a stick to the rightmost position first. After selecting a stick for the rightmost position, 
we will be left with n - 1 sticks of different sizes that will go on its left and there will be no restriction imposed by the stick we selected 
to be at the rightmost position. We just need to track whether the stick we selected at the rightmost position will be visible from the left side or not. 
And figuring that out is easy. It will be visible from the left side if it was the tallest of all the sticks we had. 
And it will not be visible from the left if it wasn't the tallest stick. So the two possibilities for the rightmost stick selection at any point 
where we have n sticks and k of them need to be visible from the left:

1. We select the tallest of the n sticks. There's only one such stick and this stick will finally be visible from the left. 
   And so we are left with the sub-problem (n - 1, k - 1).
2. We select a stick that's not the tallest one. We can do this by selecting any of the n - 1 sticks that are not the tallest one. 
   So there are n - 1 sub-problems and each of them is (n - 1, k). This stick we selected will not be visible from the left, 
   so we still gotta select k sticks from the remaining pile that will be visible, that's why the sub-problem has k, and not k - 1.
*/

class Solution {
public:
    const int MOD = 1000000007;
    long long dp[1001][1001];
    
    long long rec(int n, int k)
    {
        if(n < k || k == 0)
            return 0;
        
        if(dp[n][k] != -1)
            return dp[n][k];
        
        if(n == k)
            return dp[n][k] = 1;
        
        return dp[n][k] = (rec(n-1, k-1) + rec(n-1, k) * (n-1)) % MOD;
    }
    
    int rearrangeSticks(int n, int k) 
    {
        memset(dp, -1, sizeof(dp));
        return rec(n, k);
    }
};
