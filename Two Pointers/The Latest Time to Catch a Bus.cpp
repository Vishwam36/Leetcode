// By Vishwam Shriram Mundada
// https://leetcode.com/problems/the-latest-time-to-catch-a-bus/
// Easy

// REF : https://leetcode.com/problems/the-latest-time-to-catch-a-bus/discuss/2259211/Question-is-not-clear

/*
You are given a 0-indexed integer array buses of length n, where buses[i] represents the departure time of the ith bus. You are also given a 0-indexed 
integer array passengers of length m, where passengers[j] represents the arrival time of the jth passenger. All bus departure times are unique. 
All passenger arrival times are unique.

You are given an integer capacity, which represents the maximum number of passengers that can get on each bus.

The passengers will get on the next available bus. You can get on a bus that will depart at x minutes if you arrive at y minutes where y <= x, 
and the bus is not full. Passengers with the earliest arrival times get on the bus first.

Return the latest time you may arrive at the bus station to catch a bus. You cannot arrive at the same time as another passenger.

Note: The arrays buses and passengers are not necessarily sorted.

Example 1:
Input: buses = [10,20], passengers = [2,17,18,19], capacity = 2
Output: 16
Explanation: 
The 1st bus departs with the 1st passenger. 
The 2nd bus departs with you and the 2nd passenger.
Note that you must not arrive at the same time as the passengers, which is why you must arrive before the 2nd passenger to catch the bus.

Example 2:
Input: buses = [20,30,10], passengers = [19,13,26,4,25,11,21], capacity = 2
Output: 20
Explanation: 
The 1st bus departs with the 4th passenger. 
The 2nd bus departs with the 6th and 2nd passengers.
The 3rd bus departs with the 1st passenger and you.

Constraints:
    n == buses.length
    m == passengers.length
    1 <= n, m, capacity <= 105
    2 <= buses[i], passengers[i] <= 109
    Each element in buses is unique.
    Each element in passengers is unique.
*/

class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity)
    {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int n = buses.size(), m = passengers.size();
        
        int i = 0, j = 0;
        while(i < n)
        {
            int t = buses[i], cnt = 0;
            while(j < m && passengers[j] <= t && cnt < capacity)
            {
                ++j;
                ++cnt;
            }
            
            if(i == n-1)
            {
                if(cnt < capacity)
                {
                    --j;
                    while(j >= 0 && passengers[j] == t)
                    {
                        --t;
                        --j;
                    }
                    return t;
                }
                else
                {
                    --j;
                    t = passengers[j];
                    while(j >= 0 && passengers[j] == t)
                    {
                        --j;
                        --t;
                    }
                    return t;
                }
            }
            
            ++i;
        }
        return -1;
    }
};
