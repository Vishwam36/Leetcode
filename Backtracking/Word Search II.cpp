// By Vishwam Shriram Mundada
// https://leetcode.com/problems/word-search-ii/
// Good question

/*
Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once in a word.

Example 1:
Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]

Example 2:
Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []

Constraints:
    m == board.length
    n == board[i].length
    1 <= m, n <= 12
    board[i][j] is a lowercase English letter.
    1 <= words.length <= 3 * 10^4
    1 <= words[i].length <= 10
    words[i] consists of lowercase English letters.
    All the strings of words are unique.
*/


// REF : https://www.youtube.com/watch?v=h0kSTsLaZ-U

struct TrieNode
{
    vector<TrieNode*> children;
    bool isLeaf;
};

TrieNode* newNode()
{
    TrieNode* t = new TrieNode();
    t->children.resize(26, NULL);
    t->isLeaf = false;
    return t;
}

class Solution {
public:
    int n, m;
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};
    set<string> ans;
    vector<vector<bool> > vis;
    TrieNode* root = newNode();
    
    bool valid(int i, int j)
    {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    
    void rec(int x, int y, vector<vector<char>>& board, TrieNode* temp, string &s)
    {
        if(temp->isLeaf > 0)
            ans.insert(s);
        
        for(int k = 0; k < 4; ++k)
        {
            int ni = x + di[k];
            int nj = y + dj[k];
            
            if(valid(ni, nj) && !vis[ni][nj] && temp->children[board[ni][nj]-'a'])
            {
                vis[ni][nj] = 1;
                s.push_back(board[ni][nj]);
                rec(ni, nj, board, temp->children[board[ni][nj]-'a'], s);
                s.pop_back();
                vis[ni][nj] = 0;
            }
        }
    }
    
    void insert(string &s)
    {
        auto temp = root;
        for(auto& ch : s)
        {
            if(temp->children[ch-'a'] == NULL)
                temp->children[ch-'a'] = newNode();
            
            temp = temp->children[ch-'a'];
        }
        temp->isLeaf = true;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        n = board.size(), m = board[0].size();
        vis.resize(n, vector<bool>(m, false));
        
        for(auto& word : words)
            insert(word);
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(root->children[board[i][j]-'a'])
                {
                    vis[i][j] = 1;
                    string s = "";
                    s.push_back(board[i][j]);
                    rec(i, j, board, root->children[board[i][j]-'a'], s);
                    vis[i][j] = 0;
                }
        
        return vector<string>(ans.begin(), ans.end());
    }
};
