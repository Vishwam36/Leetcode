// By Vishwam Shriram Mundada
// https://leetcode.com/problems/longest-palindromic-substring/
// Decent

/*
Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"

Example 3:
Input: s = "a"
Output: "a"

Example 4:
Input: s = "ac"
Output: "a"
 
Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case),
*/


// App 1 : 
// TC : O(N^2)
// SC : O(N^2)

class Solution {
public:
    string longestPalindrome(string s) 
    {
        int n = s.size(), idx = 0, size = 0;
        vector<vector<bool> > dp(n, vector<bool>(n, false));
        
        for(int gap = 0; gap < n; ++gap)
        {
            for(int i = 0; i+gap < n; ++i)
            {
                int x = i;
                int y = i+gap;
                
                if(y-x <= 1)
                    dp[x][y] = s[x] == s[y];
                else
                    dp[x][y] = dp[x+1][y-1] && s[x] == s[y];
                
                if(dp[x][y] && y-x+1 > size)
                {
                    size = y-x+1;
                    idx = x;
                }
            }
        }
        
        return s.substr(idx, size);
    }
};


// App 2 : 
// TC : O(N^2)
// SC : O(N) for storing answer string

class Solution {
public:
    bool isPali(string &s)
    {
        int l = 0, r = s.size()-1;
        while(r > l)
            if(s[l++] != s[r--])
                return false;
        
        return true;
    }
    
    string longestPalindrome(string s) 
    {
        int n = s.size(), idx = 0, max_size = 0;
        for(int mid = 0; mid < n; ++mid)
        {
            for(int size = max_size+1; mid-size >= 0 && mid+size < n; ++size)
            {
                string news = s.substr(mid-size, size) + s.substr(mid, 1) + s.substr(mid+1, size);
                if(size > max_size && isPali(news))
                    idx = mid, max_size = size;
                else
                    break;
            }
        }
        string ans1 = s.substr(idx-max_size, max_size) + s.substr(idx, 1) + s.substr(idx+1, max_size);
        
        idx = -1;
        for(int mid = 1; mid < n; ++mid)
        {
            for(int size = max_size + 1; mid-size >= 0 && mid+size <= n; ++size)
            {
                string news = s.substr(mid-size, size) + s.substr(mid, size);
                if(size > max_size && isPali(news))
                    idx = mid, max_size = size;
                else
                    break;
            }
        }
        string ans2;
        if(idx != -1)
            ans2 = s.substr(idx-max_size, max_size) + s.substr(idx, max_size);
        
        if(ans1.size() > ans2.size())
            return ans1;
        return ans2;
    }
};
