// By Vishwam Shriram Mundada
// https://leetcode.com/problems/check-if-word-can-be-placed-in-crossword/
// Decent

/*
You are given an m x n matrix board, representing the current state of a crossword puzzle. The crossword contains lowercase English letters (from solved words), 
' ' to represent any empty cells, and '#' to represent any blocked cells.

A word can be placed horizontally (left to right or right to left) or vertically (top to bottom or bottom to top) in the board if:

    It does not occupy a cell containing the character '#'.
    The cell each letter is placed in must either be ' ' (empty) or match the letter already on the board.
    There must not be any empty cells ' ' or other lowercase letters directly left or right of the word if the word was placed horizontally.
    There must not be any empty cells ' ' or other lowercase letters directly above or below the word if the word was placed vertically.

Given a string word, return true if word can be placed in board, or false otherwise.

Example 1:
Input: board = [["#", " ", "#"], [" ", " ", "#"], ["#", "c", " "]], word = "abc"
Output: true
Explanation: The word "abc" can be placed as shown above (top to bottom).

Example 2:
Input: board = [[" ", "#", "a"], [" ", "#", "c"], [" ", "#", "a"]], word = "ac"
Output: false
Explanation: It is impossible to place the word because there will always be a space/letter above or below it.

Example 3:
Input: board = [["#", " ", "#"], [" ", " ", "#"], ["#", " ", "c"]], word = "ca"
Output: true
Explanation: The word "ca" can be placed as shown above (right to left). 

Constraints:
    m == board.length
    n == board[i].length
    1 <= m * n <= 2 * 10^5
    board[i][j] will be ' ', '#', or a lowercase English letter.
    1 <= word.length <= max(m, n)
    word will contain only lowercase English letters.
*/

class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word)
    {
        int n = board.size(), m = board[0].size();
        int size = word.size();
        
        vector<vector<int> > preUp(n, vector<int>(m, 0)); // preUp[i][j] stores maximum length if we store vertically and end at (i,j)
        vector<vector<int> > preLeft(n, vector<int>(m, 0)); // preLeft[i][j] stores maximum length if we store horizontally and end at (i,j) 
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(i == 0)
                {
                    if(board[i][j] != '#')
                        preUp[i][j] = 1;
                }
                else
                {
                    if(board[i][j] != '#')
                        preUp[i][j] = preUp[i-1][j] + 1;
                }
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(j == 0)
                {
                    if(board[i][j] != '#')
                        preLeft[i][j] = 1;
                }
                else
                {
                    if(board[i][j] != '#')
                        preLeft[i][j] = preLeft[i][j-1] + 1;
                }
        
        bool f = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(preUp[i][j] == size && (i < n-1 ? board[i+1][j] == '#' : 1))
                {
                    f = 0;
                    for(int x = i, y = size-1; y >= 0; --y, --x) // check for bottom-top
                    {
                        if(board[x][j] != ' ' && board[x][j] != word[y])
                        {
                            f = 1; // unfit
                            break;
                        }
                    }
                    
                    if(f == 0) // word fits properly
                        return true;
                    
                    f = 0;
                    for(int x = i, y = 0; y < size; ++y, --x) // check for top-bottom
                    {
                        if(board[x][j] != ' ' && board[x][j] != word[y])
                        {
                            f = 1; // unfit
                            break;
                        }
                    }
                    
                    if(f == 0) // word fits properly
                        return true;
                }
                
                if(preLeft[i][j] == size && (j < m-1 ? board[i][j+1] == '#' : 1))
                {
                    f = 0;
                    for(int x = j, y = size-1; y >= 0; --y, --x) // check for right-left
                    {
                        if(board[i][x] != ' ' && board[i][x] != word[y])
                        {
                            f = 1; // unfit
                            break;
                        }
                    }
                    
                    if(f == 0) // word fits properly
                        return true;
                    
                    f = 0;
                    for(int x = j, y = 0; y < size; ++y, --x) // check for left-right
                    {
                        if(board[i][x] != ' ' && board[i][x] != word[y])
                        {
                            f = 1; // unfit
                            break;
                        }
                    }
                    
                    if(f == 0) // word fits properly
                        return true;
                }
            }
        }
        
        return false;
    }
};
