// By Vishwam Shriram Mundada
// https://leetcode.com/problems/remove-k-digits/
// Decent

class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        if(k >= num.size())
            return "0";
        
        string ans = "";
        int ansSize = num.size() - k;
        
        for(auto i : num)
        {
            while(k && ans.size() && ans.back() > i)
            {
                ans.pop_back();
                --k;
            }
            ans += i;
        }
        
        ans.resize(ansSize);
        
        while(ans.size() && ans[0] == '0')
            ans.erase(ans.begin());
        
        if(ans.size() == 0)
            ans = "0";
        
        return ans;
    }
};
