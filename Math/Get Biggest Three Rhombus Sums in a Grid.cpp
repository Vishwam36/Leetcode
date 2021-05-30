// By Vishwam Shriram Mundada
// https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/
// Heavy implementation

/*
You are given an m x n integer matrix grid

A rhombus sum is the sum of the elements that form the border of a regular rhombus shape in grid. The rhombus must have the shape of a square rotated 
45 degrees with each of the corners centered in a grid cell. Below is an image of four valid rhombus shapes with the corresponding colored cells 
that should be included in each rhombus sum:

Note that the rhombus can have an area of 0, which is depicted by the purple rhombus in the bottom right corner.

Return the biggest three distinct rhombus sums in the grid in descending order. If there are less than three distinct values, return all of them.

Example 1:
Input: grid = [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]]
Output: [228,216,211]
Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
- Blue: 20 + 3 + 200 + 5 = 228
- Red: 200 + 2 + 10 + 4 = 216
- Green: 5 + 200 + 4 + 2 = 211

Example 2:
Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
Output: [20,9,8]
Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
- Blue: 4 + 2 + 6 + 8 = 20
- Red: 9 (area 0 rhombus in the bottom right corner)
- Green: 8 (area 0 rhombus in the bottom middle)

Example 3:
Input: grid = [[7,7,7]]
Output: [7]
Explanation: All three possible rhombus sums are the same, so return [7].

Constraints:
    m == grid.length
    n == grid[i].length
    1 <= m, n <= 50
    1 <= grid[i][j] <= 10^5
*/

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) 
    {
        set<int> s;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int> > d1 = grid; // prefix sum of diagonal 1
        vector<vector<int> > d2 = grid; // prefix sum of diagonal 2
        
        for(int i = 1; i < n; ++i)
            for(int j = 1; j < m; ++j)
                d1[i][j] = grid[i][j] + d1[i-1][j-1];
        
        for(int i = 1; i < n; ++i)
            for(int j = m-2; j >= 0; --j)
                d2[i][j] = grid[i][j] + d2[i-1][j+1];
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                s.insert(grid[i][j]);
                if(s.size() > 3)
                    s.erase(s.begin());
                
                bool flag = true;
                
                for(int sz = 1; flag == true; ++sz)
                {
                    if(i-2*sz >= 0 && j-sz >= 0 && j+sz < m)
                    {
                        int sum = d1[i][j] + d2[i][j] - grid[i][j];
                        if(i-sz >= 0 && j-sz >= 0)
                        {
                            sum -= d1[i-sz][j-sz];
                            sum += d2[i-sz][j-sz];
                        }
                        if(i-sz >= 0 && j+sz < m)
                        {
                            sum -= d2[i-sz][j+sz];
                            sum += d1[i-sz][j+sz];
                        }
                        
                        sum -= d1[i-2*sz][j];
                        sum -= d2[i-2*sz][j];
                        sum += grid[i-2*sz][j]; // deleted twice
                        
                        s.insert(sum);
                        if(s.size() > 3)
                            s.erase(s.begin());
                    }
                    else
                    {
                        flag = false; // we cant have rhomus of size >= sz
                    }
                }
            }
        }
        
        return vector<int> (s.rbegin(), s.rend());
    }
};
