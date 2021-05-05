// By Vishwam Shriram Mundada
// https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/
// Decent question with little maths

/*
You are given three positive integers: n, index, and maxSum. You want to construct an array nums (0-indexed) that satisfies the following conditions:

nums.length == n
nums[i] is a positive integer where 0 <= i < n.
abs(nums[i] - nums[i+1]) <= 1 where 0 <= i < n-1.
The sum of all the elements of nums does not exceed maxSum.
nums[index] is maximized.
Return nums[index] of the constructed array.

Note that abs(x) equals x if x >= 0, and -x otherwise.

Example 1:
Input: n = 4, index = 2,  maxSum = 6
Output: 2
Explanation: nums = [1,2,2,1] is one array that satisfies all the conditions.
There are no arrays that satisfy all the conditions and have nums[2] == 3, so 2 is the maximum nums[2].

Example 2:
Input: n = 6, index = 1,  maxSum = 10
Output: 3

Constraints:
1 <= n <= maxSum <= 109
0 <= index < n
*/

typedef long long ll;

class Solution {
public:
    ll sum(ll mid, ll n1, ll n2)
    {
        ll temp = mid + (mid*(mid-1));
        if(mid-1 >= n2)
            temp -= ((mid-1-n2)*(mid-n2))/2;
        else
            temp += n2-(mid-1);
        
        if(mid-1 >= n1)
            temp -= ((mid-1-n1)*(mid-n1))/2;
        else
            temp += n1-(mid-1);
        
        return temp;
    }
    
    ll bin_search(ll maxSum, ll n1, ll n2)
    {
        int l = 0, r = 1000000000, mid;
        while(r-l > 1)
        {
            mid = (l+r)/2;
            ll temp = sum(mid, n1, n2);
            
            if(temp <= maxSum)
                l = mid;
            
            else
                r = mid;
        }
        if(sum(r, n1, n2) <= maxSum)
            return r;
        
        return l;
    }
    
    int maxValue(int n, int index, int maxSum) 
    {
        int n1 = index;
        int n2 = n-index-1;
        return bin_search(maxSum, n1, n2);
    }
};
