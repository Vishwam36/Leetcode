// By Vishwam Shriram Mundada
// https://leetcode.com/problems/minimum-white-tiles-after-covering-with-carpets/
// Good question

/*
You are given a 0-indexed binary string floor, which represents the colors of tiles on a floor:

    floor[i] = '0' denotes that the ith tile of the floor is colored black.
    On the other hand, floor[i] = '1' denotes that the ith tile of the floor is colored white.

You are also given numCarpets and carpetLen. You have numCarpets black carpets, each of length carpetLen tiles. 
Cover the tiles with the given carpets such that the number of white tiles still visible is minimum. Carpets may overlap one another.

Return the minimum number of white tiles still visible.

Example 1:
Input: floor = "10110101", numCarpets = 2, carpetLen = 2
Output: 2
Explanation: 
The figure above shows one way of covering the tiles with the carpets such that only 2 white tiles are visible.
No other way of covering the tiles with the carpets can leave less than 2 white tiles visible.

Example 2:
Input: floor = "11111", numCarpets = 2, carpetLen = 3
Output: 0
Explanation: 
The figure above shows one way of covering the tiles with the carpets such that no white tiles are visible.
Note that the carpets are able to overlap one another.

Constraints:
    1 <= carpetLen <= floor.length <= 1000
    floor[i] is either '0' or '1'.
    1 <= numCarpets <= 1000
*/


// REF : https://www.youtube.com/watch?v=3lNY7MRewVI

class Solution {
public:
    vector<vector<int> > dp;
    vector<int> pre;
    int n;
    
    int rec(int idx, string &s, int nc, int l)
    {
        if(idx >= s.size() || nc == 0)
            return 0;
        
        if(dp[idx][nc] != -1)
            return dp[idx][nc];
                
        if(s[idx] == '0')
        {
            dp[idx][nc] = rec(idx+1, s, nc, l);
        }
        else
        {
            int next = min((int)s.size()-1, idx+l-1);
            int white = pre[next];
            if(idx-1 >= 0)
                white -= pre[idx-1];
            
            dp[idx][nc] = max(white + rec(idx+l, s, nc-1, l), rec(idx+1, s, nc, l));
        }
        
        return dp[idx][nc];
    }
    
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen)
    {
        n = floor.size();
        dp.resize(n+1, vector<int>(numCarpets+1, -1));
        
        pre.resize(n, 0);
        for(int i = 0; i < n; ++i)
        {
            if(floor[i] == '1')
                pre[i] = (i-1 >= 0 ? pre[i-1]+1 : 1);
            else
                pre[i] = (i-1 >= 0 ? pre[i-1] : 0);
        }
        
        return pre[n-1] - rec(0, floor, numCarpets, carpetLen);
    }
};
