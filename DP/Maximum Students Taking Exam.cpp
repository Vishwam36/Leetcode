// By Vishwam Shriram Mundada
// https://leetcode.com/problems/maximum-students-taking-exam/
// Good question, DP, Bit Masking
// Ref : https://www.youtube.com/watch?v=WBlHRJV3YRs

/*
Given a m * n matrix seats  that represent seats distributions in a classroom. If a seat is broken, it is denoted by '#' character 
otherwise it is denoted by a '.' character.

Students can see the answers of those sitting next to the left, right, upper left and upper right, but he cannot see the answers of the student 
sitting directly in front or behind him. Return the maximum number of students that can take the exam together without any cheating being possible..

Students must be placed in seats in good condition.

Example 1:
Input: seats = [["#",".","#","#",".","#"],
                [".","#","#","#","#","."],
                ["#",".","#","#",".","#"]]
Output: 4
Explanation: Teacher can place 4 students in available seats so they don't cheat on the exam. 

Example 2:
Input: seats = [[".","#"],
                ["#","#"],
                ["#","."],
                ["#","#"],
                [".","#"]]
Output: 3
Explanation: Place all students in available seats. 

Example 3:
Input: seats = [["#",".",".",".","#"],
                [".","#",".","#","."],
                [".",".","#",".","."],
                [".","#",".","#","."],
                ["#",".",".",".","#"]]
Output: 10
Explanation: Place students in available seats in column 1, 3 and 5.

Constraints:
    seats contains only characters '.' and'#'.
    m == seats.length
    n == seats[i].length
    1 <= m <= 8
    1 <= n <= 8
*/

class Solution {
public:
    // 2^8 = 256
    int dp[9][9][257][257];
    int n, m;
    
    // preRow is bitmask of previous row of i
    // currRow is bitmask of current row
    // in bitmasks bit is set if student is placed there
    int rec(int i, int j, int preRow, int currRow, vector<vector<char>>& seats)
    {
        if(dp[i][j][preRow][currRow] != -1)
            return dp[i][j][preRow][currRow];
        
        if(i == n)
            return 0;
        
        // if top-left and top-right and left are empty(unset) then only we can place student
        // bottom-left, bottom-right, right are already unset because we havent reaches there
        // so, if tl, tr, l are all false and flag is true then only we can place student
        bool tl = false, tr = false, l = false, flag = false;
        if(seats[i][j] == '.')
        {
            flag = true; // we can place student at (i,j)
            if(j < m-1)
                tr = ((1 << (j+1)) & (preRow)) != 0; // whether top-right is set
            if(i > 0 && j > 0)
                tl = ((1 << (j-1)) & (preRow)) != 0; // whether top-left is set
            if(j > 0)
                l = ((1 << (j-1)) & (currRow)) != 0; // whether left is set
        }
        
        int place = 0, not_place = 0, new_i = i, new_j = j;
        if(j == m-1)
        {
            // if column is last one then for new_i preRow will be currRow of i 
            new_i = i+1;
            new_j = 0;
            not_place = rec(new_i, new_j, currRow, 0, seats);
            if(flag && !tl && !l && !tr)
                place = rec(new_i, new_j, ((currRow) | (1 << j)), 0, seats)+1;
        }
        else
        {
            new_j = j+1;
            not_place = rec(new_i, new_j, preRow, currRow, seats);
            if(flag && !tl && !l && !tr && flag)
                place = rec(new_i, new_j, preRow, ((currRow) | (1 << j)), seats)+1;
        }
                
        return dp[i][j][preRow][currRow] = max(place, not_place);
    }
    
    int maxStudents(vector<vector<char>>& seats) 
    {
        memset(dp, -1, sizeof(dp));
        n = seats.size(), m = seats[0].size();
        return rec(0, 0, 0, 0, seats);
    }
};
