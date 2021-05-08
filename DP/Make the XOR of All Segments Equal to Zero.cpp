// By Vishwam Shriram Mundada
// https://leetcode.com/problems/make-the-xor-of-all-segments-equal-to-zero/
// V.Good question

/*
You are given an array nums and an integer k. The XOR of a segment [left, right] where left <= right is the XOR of all the elements with indices between left and right, 
inclusive: nums[left] XOR nums[left+1] XOR ... XOR nums[right].

Return the minimum number of elements to change in the array such that the XOR of all segments of size k is equal to zero.

Example 1:
Input: nums = [1,2,0,3,0], k = 1
Output: 3
Explanation: Modify the array from [1,2,0,3,0] to from [0,0,0,0,0].

Example 2:
Input: nums = [3,4,5,2,1,7,3,4,7], k = 3
Output: 3
Explanation: Modify the array from [3,4,5,2,1,7,3,4,7] to [3,4,7,3,4,7,3,4,7].

Example 3:
Input: nums = [1,2,4,1,2,5,1,2,6], k = 3
Output: 3
Explanation: Modify the array from [1,2,4,1,2,5,1,2,6] to [1,2,3,1,2,3,1,2,3].
 

Constraints:
1 <= k <= nums.length <= 2000
0 <= nums[i] < 210
*/

class Solution {
public:
    int minChanges(vector<int>& nums, int k) 
    {
        int n = nums.size();
        // frequency of the number at position i where i in [0, k - 1]
        vector<unordered_map<int, int> > freq(k, unordered_map<int, int>());
        for(int i = 0; i < n; ++i)
        {
            int pos = i % k;
            freq[pos][nums[i]]++;
        }
        /* dp[i][j] = minimum total number of elements we need to change from index 0 to i 
        so that the xor of the subarray from index 0 to i is equal to j */
        vector<vector<int> > dp(k, vector<int>(1024, n+1));
        
        // best value till last position
        int min_till_last = n+1;
        for(int i = 0; i < k; ++i)
        {
            // how many i indices exist in the array
            int count_i = n/k + ((n % k) > i ? 1 : 0);
            // will track best value at i
            int min_at_i = n+1;
            
            // find the best way to make the sum equal to j from index 0 to i
            for(int j = 0; j < 1024; ++j)
            {
                if(i == 0)
                    dp[i][j] = count_i - freq[i][j];
                
                else
                {
                    // iterate over all numbers that occur at index i
                    for(auto& [key, v] : freq[i])
                    {
                        dp[i][j] = min(dp[i][j], dp[i-1][j^key] + count_i - v);
                    }
                    // this will do for all the numbers that don't occur at index i
                    // we are changing all the numbers at index i with an arbitrary number that gives best result
                    dp[i][j] = min(dp[i][j], min_till_last + count_i);
                }
                min_at_i = min(min_at_i, dp[i][j]);
            }
            min_till_last = min_at_i;
        }
        // ans is xor till k elements is 0
        return dp[k-1][0];
    }
};
