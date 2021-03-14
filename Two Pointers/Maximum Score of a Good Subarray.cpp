// By Vishwam Shriram Mundada
// https://leetcode.com/problems/maximum-score-of-a-good-subarray/
// Decent

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) 
    {
        int n = nums.size(), ans = 0, i = k, j = k, minEle = nums[k];
        
        while(i >= 0 && j < n)
        {
            ans = max(ans, minEle * (j-i+1));
            
            if(i == 0 && j == n-1)
                break;
            
            if(i > 0 && j < n-1)
            {
                if(nums[i-1] > nums[j+1])
                {
                    --i;
                    minEle = min(nums[i], minEle);
                }
                else
                {
                    ++j;
                    minEle = min(nums[j], minEle);
                }
            }
            else if(i == 0)
            {
                j++;
                minEle = min(nums[j], minEle);
            }
            else
            {
                --i;
                 minEle = min(nums[i], minEle);
            }
        }
        return ans;
    }
};
