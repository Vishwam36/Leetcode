// By Vishwam Shriram Mundada
// Standard

class Solution {
public:
    int n, m;
    
    bool valid(int x, int y, vector<vector<char> > &board, char num)
    {
        for(int i = 0; i < n; ++i)
            if(board[i][y] == num)
                return false;
        
        for(int i = 0; i < m; ++i)
            if(board[x][i] == num)
                return false;
        
        int xs = x - x%3;
        int ys = y - y%3;
        
        for(int i = 0; i < 3; ++i)
            for(int j = 0; j < 3; ++j)
                if(board[xs+i][ys+j] == num)
                    return false;
        
        return true;
    }
    
    bool rec(int x, int y, vector<vector<char> > &board)
    {
        if(x == n)
            return true;
        if(y == m)
            return rec(x+1, 0, board);
        if(board[x][y] != '.') 
            return rec(x, y+1, board);
        
        for(char ch = '1'; ch <= '9'; ++ch)
        {
            if(!valid(x, y, board, ch))
                continue;
            
            board[x][y] = ch;
            if(rec(x, y+1, board))
                return true;
            board[x][y] = '.';
        }
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) 
    {
        n = 9, m = 9;
        rec(0, 0, board);
    }
};
