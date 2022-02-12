// By Vishwam Shriram Mundada
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/113/math/819/
// Easy

class Solution {
public:
    int mySqrt(int x)
    {
        long long l = 0, r = 100000, mid;
        
        while(r-l > 1)
        {
            mid = (l+r)/2;
            
            if(mid*mid > x)
                r = mid-1;
            else
                l = mid;
        }
        
        if(r*r <= x)
            return r;
        return l;
    }
};
