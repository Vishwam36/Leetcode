// By Vishwam Shriram Mundada
// https://leetcode.com/problems/median-of-two-sorted-arrays/
// Good question
// REF : https://www.youtube.com/watch?v=NTop3VTjmxk&ab_channel=takeUforward

/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Example 3:
Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000

Example 4:
Input: nums1 = [], nums2 = [1]
Output: 1.00000

Example 5:
Input: nums1 = [2], nums2 = []
Output: 2.00000

Constraints:
nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-10^6 <= nums1[i], nums2[i] <= 10^6
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        if(n2 < n1)
            return findMedianSortedArrays(nums2, nums1); // nums1 should be lesser for little better TC
        
        int leftCnt = (n1+n2+1)/2; // no of elements we want in left of partition        
        int l1, l2, r1, r2;
        int low = 0, high = n1, cut1, cut2;
        // we are doing binary search on cuts and not elements
        while(low <= high)
        {
            cut1 = (high + low)/2;
            cut2 = leftCnt - cut1;
                
            l1 = cut1 > 0 ? nums1[cut1-1] : INT_MIN;
            r1 = cut1 < n1 ? nums1[cut1] : INT_MAX;
            
            l2 = cut2 > 0 ? nums2[cut2-1] : INT_MIN;
            r2 = cut2 < n2 ? nums2[cut2] : INT_MAX;
            
            if(l1 <= r2 && l2 <= r1) // found partition
            {
                if((n1+n2)%2 == 0)
                    return (double)(max(l1, l2) + min(r1, r2))/2;
                else
                    return (double)(max(l1, l2));
            }
            
            if(l1 > r2)
                high = cut1-1;
            else if(l2 > r1)
                low = cut1+1;
        }
        return 0;
    }
};
