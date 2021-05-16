// By Vishwam Shriram Mundada
// https://leetcode.com/problems/sum-of-floored-pairs/
// Good question

/*
Given an integer array nums, return the sum of floor(nums[i] / nums[j]) for all pairs of indices 0 <= i, j < nums.length in the array. 
Since the answer may be too large, return it modulo 109 + 7.
The floor() function returns the integer part of the division.

Example 1:
Input: nums = [2,5,9]
Output: 10
Explanation:
floor(2 / 5) = floor(2 / 9) = floor(5 / 9) = 0
floor(2 / 2) = floor(5 / 5) = floor(9 / 9) = 1
floor(5 / 2) = 2
floor(9 / 2) = 4
floor(9 / 5) = 1
We calculate the floor of the division for every pair of indices in the array then sum them up.

Example 2:
Input: nums = [7,7,7,7,7,7,7]
Output: 49

Constraints:
1 <= nums.length <= 105
1 <= nums[i] <= 105
*/

/*
Hint! The Only noticeable part is the constraints. Every Element of the array lies in the range [1,1e5] which is going to help us...How?
Idea:-

1. Fix the denominator, for every denominator value (y) in the range [1,1e5], let's say we have 'x' as the answer of floor division, 
   then I have the range where the numerator lies will be [xy,min(x(y+1)-1,1e5]
2. Find the number of elements lying in the above range by precalculating the prefix sum of frequencies of the elements of the array.
3. Our answer would be incremented by freq[y] * freq[range] * x , for every y belongs to [1,1e5]
4. Time Complexity:- O(nlogn)
*/

typedef long long ll;
const int MAXN = 100001;
const int MOD = 1000000007;

class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) 
    {
        ll ans = 0;
        int n = nums.size();
        vector<int> freq(MAXN, 0);
        for(auto num : nums)
            freq[num]++;
        
        for(int i = 1; i < MAXN; ++i)
            freq[i] = freq[i] + freq[i-1];
        
        for(int i = 1; i < MAXN; ++i)
        {
            if(freq[i] - freq[i-1] > 0) // means i is present in nums
            {
                ll sum = 0;
                for(int j = 1; j*i < MAXN; ++j)
                {
                    int low = i*j;
                    int high = min(100000, i*(j+1)-1);
                    
                    int cnt = freq[high] - freq[low-1];
                    
                    sum += cnt * j;
                    sum %= MOD;
                }
                
                int f = freq[i] - freq[i-1];
                ans += f * sum;
                ans %= MOD;
            }
        }
        return ans;
    }
};
