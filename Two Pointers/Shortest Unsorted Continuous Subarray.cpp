// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
// Decent

class Solution {
public:
    int findUnsortedSubarray(vector<int>& a) 
    {
        int n = a.size();
        int st = -1, end = -2, mini = INT_MAX, maxx = INT_MIN;

        for(int i = 0; i < n; ++i)
        {
            maxx = max(maxx, a[i]);
            if(a[i] != maxx)
            {
                end = i;
            }
        }
        
        for(int i = n-1; i >= 0; --i)
        {
            mini = min(mini, a[i]);
            if(a[i] != mini)
            {
                st = i;
            }
        }

        return max(0, end-st+1);
    }
};
