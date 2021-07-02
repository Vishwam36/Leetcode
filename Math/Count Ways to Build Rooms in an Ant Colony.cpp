// By Vishwam Shriram Mundada
// https://leetcode.com/problems/count-ways-to-build-rooms-in-an-ant-colony/
// Good question, Math, Graph
// REF : https://www.youtube.com/watch?v=MGKLPpR6NKI

/*
You are an ant tasked with adding n new rooms numbered 0 to n-1 to your colony. You are given the expansion plan as a 0-indexed integer array of length n, 
prevRoom, where prevRoom[i] indicates that you must build room prevRoom[i] before building room i, and these two rooms must be connected directly. Room 0 
is already built, so prevRoom[0] = -1. The expansion plan is given such that once all the rooms are built, every room will be reachable from room 0.

You can only build one room at a time, and you can travel freely between rooms you have already built only if they are connected. You can choose to build 
any room as long as its previous room is already built.

Return the number of different orders you can build all the rooms in. Since the answer may be large, return it modulo 109 + 7.

Example 1:
Input: prevRoom = [-1,0,1]
Output: 1
Explanation: There is only one way to build the additional rooms: 0 → 1 → 2

Example 2:
Input: prevRoom = [-1,0,0,1,2]
Output: 6
Explanation:
The 6 ways are:
0 → 1 → 3 → 2 → 4
0 → 2 → 4 → 1 → 3
0 → 1 → 2 → 3 → 4
0 → 1 → 2 → 4 → 3
0 → 2 → 1 → 3 → 4
0 → 2 → 1 → 4 → 3

Constraints:
    n == prevRoom.length
    2 <= n <= 10^5
    prevRoom[0] == -1
    0 <= prevRoom[i] < n for all 1 <= i < n
    Every room is reachable from room 0 once all the rooms are built.
*/

#define ll long long

class Solution {
public:
    ll MOD = 1000000007;
    vector<ll> fact;
    vector<ll> invFact;
    int n;
    
    ll myPow(int base, int power)
    {
        if(power == 0)
            return 1;
        
        if(power % 2 == 0)
        {
            ll ans = myPow(base, power/2);
            return ((ll)ans * ans) % MOD;
        }
        else
        {
            ll ans = myPow(base, power/2);
            return ((((ll)ans * ans) % MOD) * base) % MOD;
        }
        return 1;
    }
    
    void init()
    {
        for(int i = 1; i < n; ++i)
        {
            fact[i] = (i * fact[i-1]) % MOD;
            invFact[i] = myPow(fact[i], MOD-2);
        }
    }
    
    ll ncr(int N, int R)
    {
        return (((fact[N] * invFact[R]) % MOD) * invFact[N-R]) % MOD;
    }
    
    // pair<ll, ll> -> {subWays, subTreeNodeCount}
    pair<ll, ll> dfs(int u, vector<int> adj[])
    {
        if(adj[u].size() == 0)
            return {1, 1};
        
        int nodeCnt = 0; // total no of nodes in all subtrees
        ll ways = 1;
        
        for(auto v : adj[u])
        {
            auto next = dfs(v, adj);
            nodeCnt += next.second;
            ll subWays = next.first;
            
            ways = (((ways * subWays) % MOD) * ncr(nodeCnt, next.second)) % MOD;
        }
        return {ways, nodeCnt+1}; // +1 for current node
    }
    
    int waysToBuildRooms(vector<int>& prevRoom) 
    {
        n = prevRoom.size();
        fact = vector<ll>(n, 1);
        invFact = vector<ll>(n, 1);
        init();
        
        vector<int> adj[n];
        for(int i = 1; i < n; ++i)
            adj[prevRoom[i]].push_back(i);
        
        return dfs(0, adj).first;
    }
};
