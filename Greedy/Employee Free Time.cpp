// By Vishwam Shriram Mundada
// https://www.lintcode.com/problem/850/description
// Decent

/*
We are given a list schedule of employees, which represents the working time for each employee.
Each employee has a list of non-overlapping Intervals, and these intervals are in sorted order.
Return the list of finite intervals representing common, positive-length free time for all employees, also in sorted order.

The Intervals is an 1d-array. Each two numbers shows an interval. For example, [1,2,8,10] represents that the employee works in [1,2] and [8,10].
Also, we wouldn't include intervals like [5, 5] in our answer, as they have zero length.

1.schedule and schedule[i] are lists with lengths in range [1, 100].
2.0 <= schedule[i].start < schedule[i].end <= 10^8.

Example

Example 1:
Input：schedule = [[1,2,5,6],[1,3],[4,10]]
Output：[(3,4)]

Explanation:
There are a total of three employees, and all common
free time intervals would be [-inf, 1], [3, 4], [10, inf].
We discard any intervals that contain inf as they aren't finite.

Example 2:
Input：schedule = [[1,3,6,7],[2,4],[2,5,9,12]]
Output：[(5,6),(7,9)]

Explanation：
There are a total of three employees, and all common
free time intervals would be [-inf, 1], [5, 6], [7, 9],[12,inf].
We discard any intervals that contain inf as they aren't finite.
*/

/**
 * Definition of Interval:
 * class Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    Interval getIn(int s, int e)
    {
        Interval i;
        i.start = s;
        i.end = e;
        return i;
    }

    vector<Interval> employeeFreeTime(vector<vector<int>> &schedule)
    {
        vector<Interval> ans;
        map<int, int> m;
        for(auto& s : schedule)
            for(int i = 0; i < s.size();)
            {
                m[s[i++]]++;
                m[s[i++]]--;
            }

        int sum = 0;
        int start = INT_MIN;

        for(auto it : m)
        {
            if(it.second > 0)
            {
                if(sum == 0)
                    ans.push_back(getIn(start, it.first));
                
                sum += it.second;
            }
            else if(it.second < 0)
            {
                sum += it.second;
                if(sum == 0)
                    start = it.first;
            }
        }
        ans.erase(ans.begin());
        return ans;
    }
};
