// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/
// Decent

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), l = 0, r = 0, ans = 0;
        vector<int> vis(3, 0);
        while(r < n)
        {
            while(r < n && !(vis[0] > 0 && vis[1] > 0 && vis[2] > 0))
            {
                vis[s[r]-'a']++;
                r++;
            }
            if(vis[0] > 0 && vis[1] > 0 && vis[2] > 0)
            {
                ans += n-r+1;
            }
            vis[s[l]-'a']--;
            l++;
        }

        while(vis[0] > 0 && vis[1] > 0 && vis[2] > 0)
        {
            ans++;
            vis[s[l]-'a']--;
            l++;
        }

        return ans;
    }
};
