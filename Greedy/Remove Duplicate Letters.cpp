// By Vishwam Shriram Mundada
// https://leetcode.com/problems/remove-duplicate-letters/
// Good question

class Solution {
public:
    string removeDuplicateLetters(string s) 
    {
        string ans = "";
        
        int count[26] = {0};
        bool taken[26] = {false};
        
        for(auto i : s)
            count[i-'a']++;
        
        for(auto i : s)
        {
            int a = i - 'a';
            
            count[a]--;
            
            if(taken[a])
                continue;
            
            while(!ans.empty() && i < ans.back() && count[ans.back() - 'a'])
            {
                taken[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            
            ans += i;
            taken[a] = true;
        }
        return ans;
    }
};
