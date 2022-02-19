// By Vishwam Shriram Mundada
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/118/trees-and-graphs/843/
// Easy

/*
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example 1:
Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Surrounded regions should not be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. 
			Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. 
			Two cells are connected if they are adjacent cells connected horizontally or vertically.

Example 2:
Input: board = [["X"]]
Output: [["X"]]

Constraints:
    m == board.length
    n == board[i].length
    1 <= m, n <= 200
    board[i][j] is 'X' or 'O'.
*/

class Solution {
public:
    int di[4] = {0, 0, -1, 1};
    int dj[4] = {-1, 1, 0, 0};
    int n, m;
    vector<vector<bool> > vis;
    
    bool valid(int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    
    bool isSurrounded(vector<vector<char>>& board, set<pair<int, int> >& oxs)
    {
        for(auto p : oxs)
        {
            int i = p.first;
            int j = p.second;
            
            if(!valid(i,j))
                return false;
        }
        return true;
    }
    
    void process(vector<vector<char>>& board, int x, int y)
    {
        set<pair<int, int> > oxs, os;
        queue<pair<int, int> > q;
        q.push({x,y});
        vis[x][y] = true;
        
        while(!q.empty())
        {
            auto p = q.front(); q.pop();
            int i = p.first;
            int j = p.second;
            
            os.insert({i,j});
            for(int k = 0; k < 4; ++k)
                oxs.insert({i+di[k], j+dj[k]});
            
            for(int k = 0; k < 4; ++k)
            {
                int ni = i + di[k];
                int nj = j + dj[k];
                
                if(valid(ni, nj) && board[ni][nj] == 'O' && !vis[ni][nj])
                {
                    vis[ni][nj] = true;
                    q.push({ni,nj});
                }
            }
        }
        
        if(isSurrounded(board, oxs))
            for(auto p : os)
                board[p.first][p.second] = 'X'; // flip
    }
    
    void solve(vector<vector<char>>& board) 
    {
        n = board.size(), m = board[0].size();
        vis.resize(n, vector<bool>(m, false));
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(board[i][j] == 'O' && !vis[i][j])
                    process(board, i, j);
    }
};
