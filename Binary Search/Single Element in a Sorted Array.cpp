// By Vishwam Shriram Mundada
// https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        
        int l = 0, r = nums.size()-1;
        while(r-l > 1)
        {
            int mid = (l+r)/2;
            
            if(mid % 2 == 0)
            {
                if(nums[mid] == nums[mid+1])
                    l = mid+2;
                else
                    r = mid;
            }
            else
            {
                if(nums[mid] == nums[mid-1])
                    l = mid+1;
                else
                    r = mid;
            }
        }
        
        return nums[l];
    }
};
