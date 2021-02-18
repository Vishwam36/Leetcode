// By vishwam Shriram Mundada
// https://leetcode.com/contest/weekly-contest-228/problems/minimum-limit-of-balls-in-a-bag/
// Good question
// Applying Binary Search on number of balls in a bag

bool isValid(vector<int> nums, int requiredBalls, int maxOperations)
{
    for(int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] > requiredBalls)
        {
            maxOperations -= (nums[i] / requiredBalls) - (nums[i] % requiredBalls == 0 ? 1 : 0);
            if(maxOperations < 0)
            {
                return false;
            }
        }
    }
    return true;
}

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) 
    {
        int n = nums.size();
        int max_element = INT_MIN;
        for(int i = 0; i < n; ++i)
        {
            max_element = max(nums[i], max_element);
        }
        
        int l = 1, r = max_element, mid = 0, ans = INT_MAX;
        
        while(l <= r)
        {
            mid = (l+r)/2;
            
            if(isValid(nums, mid, maxOperations))
            {
                ans = min(ans, mid);
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return ans;
    }
};
