// By Vishwam Shriram Mundada
// https://leetcode.com/problems/minimum-xor-sum-of-two-arrays/
// Decent

/*
You are given two integer arrays nums1 and nums2 of length n.

The XOR sum of the two integer arrays is (nums1[0] XOR nums2[0]) + (nums1[1] XOR nums2[1]) + ... + (nums1[n - 1] XOR nums2[n - 1]) (0-indexed).

    For example, the XOR sum of [1,2,3] and [3,2,1] is equal to (1 XOR 3) + (2 XOR 2) + (3 XOR 1) = 2 + 0 + 2 = 4.

Rearrange the elements of nums2 such that the resulting XOR sum is minimized.

Return the XOR sum after the rearrangement.

 

Example 1:
Input: nums1 = [1,2], nums2 = [2,3]
Output: 2
Explanation: Rearrange nums2 so that it becomes [3,2].
The XOR sum is (1 XOR 3) + (2 XOR 2) = 2 + 0 = 2.

Example 2:
Input: nums1 = [1,0,3], nums2 = [5,3,4]
Output: 8
Explanation: Rearrange nums2 so that it becomes [5,4,3]. 
The XOR sum is (1 XOR 5) + (0 XOR 4) + (3 XOR 3) = 4 + 4 + 0 = 8.

Constraints:
    n == nums1.length
    n == nums2.length
    1 <= n <= 14
    0 <= nums1[i], nums2[i] <= 10^7
*/

class Solution {
public:
    int n;
    vector<vector<int> > m;
    int dp[1000000];
    
    int rec(int index, vector<int>& nums1, vector<int>& nums2, int sum, int mask)
    {
        if(index == n)
            return 0;
        
        if(dp[mask] != -1)
            return dp[mask];
        
        int ans = INT_MAX;
        for(int i = 0; i < n; ++i)
        {
            if(((1 << i) & (mask)) != 0) // check if previously ith column element has picked or not
                continue;
            
            ans = min(ans, rec(index+1, nums1, nums2, sum, ((mask) | (1 << i)))+m[index][i]); // mask current column and add current m[row][col]
            // we dont hasve to worry about marking masking row because each time we are already picking next row
        }
        return dp[mask] = ans;
    }
    
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) 
    {
        n = nums1.size();
        memset(dp, -1, sizeof(dp));
        m.resize(n, vector<int>(n));
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                m[i][j] = nums1[i] ^ nums2[j];
        
        // after calculating this matrix (write down u will get better)
        // problem is reduced to picking n elements from matrix s.t each element has unique pair of row and column
        
        return rec(0, nums1, nums2, 0, 0);
    }
};
