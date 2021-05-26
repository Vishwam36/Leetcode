// By Vishwam Shriram Mundada
// https://leetcode.com/problems/merge-intervals/
// Easy

/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

Constraints:
    1 <= intervals.length <= 104
    intervals[i].length == 2
    0 <= starti <= endi <= 104
*/

// intuition
// If we sort the intervals by their start value, then each set of intervals that can be merged will appear as a contiguous "run" in the sorted list.

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            if(a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        });
        
        vector<vector<int> > ans;
        vector<int> temp = {intervals[0][0], intervals[0][1]};
        int last = 0;
        for(int i = 1; i < intervals.size(); ++i)
        {
            if(intervals[i][0] <= intervals[last][1])
            {
                if(intervals[i][1] > intervals[last][1])
                {
                    last = i;
                    temp[1] = intervals[i][1];
                }
            }
            else
            {
                ans.push_back(temp);
                last = i;
                temp = {intervals[i][0], intervals[i][1]};
            }
        }
        ans.push_back(temp);
        return ans;
    }
};
