// https://leetcode.com/problems/count-the-number-of-ideal-arrays/
// Good
// REF : https://www.youtube.com/watch?v=Ar0AEWaO2Xk

class Solution {
public:
    #define ll long long
    ll mod = 1e9 + 7;
    vector<vector<ll> > dp; // dp[i][j] -> number of ways to arrange j elements [1...j] in length i
    vector<vector<ll> > count; // count[i][j] -> number of arrangements ending with value i and number of unique elements j
    
    void calculateCounts(int mv)
    {
        for(int val = 1; val <= mv; ++val)
        {
            count[val][1] = 1;
            for(int j = val+val; j <= mv; j += val)
                for(int k = 0; k < 20; ++k)
                    count[j][k+1] += count[val][k];
        }
    }
    
    ll rec(int n, int k)
    {
        if(n == 0)
            return k == 0;
        if(k == 0)
            return 0;
        
        if(dp[n][k] != -1)
            return dp[n][k];
        
        ll ans = 0;
        ans += rec(n-1, k);
        ans += rec(n-1, k-1);
        
        return dp[n][k] = ans % mod;
    }
    
    int idealArrays(int n, int maxValue) 
    {
        dp.resize(n+1, vector<ll>(21, -1));
        count.resize(maxValue+1, vector<ll>(21, 0));
        
        calculateCounts(maxValue);
        ll ans = 0;
        
        for(int k = 1; k <= maxValue; ++k)
            for(int l = 1; l < 20; ++l)
                ans += (rec(n, l) * count[k][l]) % mod;
        
        return ans % mod;
    }
};
