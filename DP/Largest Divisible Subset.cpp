// https://leetcode.com/problems/largest-divisible-subset/description/
// Ref : https://www.youtube.com/watch?v=gDuZwBW9VvM
// Good question

class Solution {
public:
    #define ll long long
    vector<int> largestDivisibleSubset(vector<int>& v) 
    {
        int n = v.size();
        sort(v.begin(), v.end());
        vector<int> ans, dp(n, 1), hash(n, -1);
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(v[i] % v[j] == 0 && dp[i] < dp[j]+1)
                {
                    dp[i] = dp[j]+1;
                    hash[i] = j;
                }
            }
        }

        int maxSize = 0, idx = 0;
        for(int i = 0; i < n; ++i)
        {
            if(maxSize < dp[i])
            {
                maxSize = dp[i];
                idx = i;
            }
        }

        while(hash[idx] != -1)
        {
            ans.push_back(v[idx]);
            idx = hash[idx];
        }
        if(ans.size() == 0 || ans.back() != v[idx])
        {
            ans.push_back(v[idx]);
        }

        return ans;
    }
};
