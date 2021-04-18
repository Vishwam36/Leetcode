// By Vishwam Shriram Mundada
// https://leetcode.com/problems/n-queens-ii/
// nothing to do when u have solved N-Queen I

class Solution {
public:
    int ans = 0;
    
    bool canPlace(int x, int y, int n, vector<string> &temp)
    {
        for(int i = x; i >= 0; --i)
            if(temp[i][y] == 'Q')
                return 0;

        int i = x, j = y;
        while(i-- && j--)
            if(temp[i][j] == 'Q')
                return 0;

        i = x, j = y;
        while(i-- && j++ < n)
            if(temp[i][j] == 'Q')
                return 0;

        return 1;
    }

    void rec(int x, int n, vector<string> &temp)
    {
        if(x == n)
        {
            ans++;
            return;
        }

        for(int i = 0; i < n; ++i)
        {
            if(canPlace(x, i, n, temp))
            {
                temp[x][i] = 'Q';
                rec(x+1, n, temp);
                temp[x][i] = '.';
            }
        }
    }
    
    int totalNQueens(int n) 
    {
        ans = 0;
        vector<string> temp(n, string(n, '.'));
        rec(0, n, temp);
        return ans;
    }
};
