// By Vishwam Shriram Mundada
// https://leetcode.com/problems/minimum-garden-perimeter-to-collect-enough-apples/
// Decent

/*
In a garden represented as an infinite 2D grid, there is an apple tree planted at every integer coordinate. 
The apple tree planted at an integer coordinate (i, j) has |i| + |j| apples growing on it.

You will buy an axis-aligned square plot of land that is centered at (0, 0).
Given an integer neededApples, return the minimum perimeter of a plot such that at least neededApples apples are inside or on the perimeter of that plot.

Example 1:
Input: neededApples = 1
Output: 8
Explanation: A square plot of side length 1 does not contain any apples.
However, a square plot of side length 2 has 12 apples inside (as depicted in the image above).
The perimeter is 2 * 4 = 8.

Example 2:
Input: neededApples = 13
Output: 16

Example 3:
Input: neededApples = 1000000000
Output: 5040

Constraints:
    1 <= neededApples <= 10^15
*/

class Solution {
public:
    #define ll long long
    vector<ll> dp;
    
    ll MAX = 1e15;
    ll rb = 1e5;
    
    void init()
    {
        // dp[i] denotes that square with side 2*i will have how many apples
        dp[1] = 12;
        
        for(ll i = 2; i <= 100000; ++i)
        {
            dp[i] = dp[i-1];
            
            ll j = 2*i;
            dp[i] += 8*(((j)*(j+1))/2 - ((i)*(i-1))/2);
            dp[i] -= 4*(i+j);
            
            if(dp[i] >= MAX)
            {
                rb = i; // till which point I need to calulate
                break;
            }
        }
    }
    
    ll search(ll need)
    {
        ll l = 1, r = rb, mid;
        
        while(r-l > 1)
        {
            mid = (l+r)/2;
            
            if(dp[mid] >= need)
                r = mid;
            else
                l = mid;
        }
        if(dp[l] >= need)
            return l;
        return r;
    }
    
    long long minimumPerimeter(long long need)
    {
        dp = vector<ll>(100001);
        init();
        
        return search(need)*2*4; // perimeter
    }
};
