// By Vishwam Shriram Mundada
// https://leetcode.com/problems/jump-game-ii/
// Decent

class Solution {
public:
    int jump(vector<int>& nums)
    {
        if(nums.size() == 1)
            return 0;
        
        int pastReach = nums[0], nextReach = nums[0], jumps = 0, i = 0, nextIndex = 0;
        while(i < nums.size())
        {
            jumps++;
            while(i <= pastReach)
            {
                if(i+nums[i] >= nextReach)
                {
                    nextIndex = i;
                    nextReach = i + nums[i];
                }
                ++i;
                if(i >= nums.size())
                {
                    return jumps;
                }
            }
            i = nextIndex;
            pastReach = nextReach;
        }
        return jumps;
    }
};
