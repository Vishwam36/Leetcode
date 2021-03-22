// By Vishwam Shriram Mundada
// https://leetcode.com/problems/wiggle-subsequence/
// Decent

/*
(+ve) * (+ve )=( +ve)
(-ve) * (-ve )=( +ve)
(+ve) * (-ve )=( -ve)

Since every wiggle in the array represents either a positive or negative difference we can sum up all the wiggles that are caused and return the max

if the first wiggle was due to increase or upwards i.e (+ve) * (nums[i+1]-nums[i])>0 (using 1)
if the first wiggle was due to decrease or downwards (-ve) * (nums[i+1]-nums[i])>0 (using 2)
The maximum of the above cases would be the maxLength of the wiggling subsequence in the given array nums.
*/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums)
    {
        if(nums.size() == 1)
            return 1;
        
        // we are concerned with size and not elements
        int sign = 1, ans1 = 1, ans2 = 1;
        for(int i = 0; i < nums.size()-1; ++i)
        {
            if(sign * (nums[i+1] - nums[i]) > 0)
            {
                ans1++;
                sign *= -1;
            }
        }
        
        sign = -1;
        for(int i = 0; i < nums.size()-1; ++i)
        {
            if(sign * (nums[i+1] - nums[i]) > 0)
            {
                ans2++;
                sign *= -1;
            }
        }
        
        return max(ans1, ans2);
    }
};
