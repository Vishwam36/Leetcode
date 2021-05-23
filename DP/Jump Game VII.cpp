// By Vishwam Shriram Mundada
// https://leetcode.com/problems/jump-game-vii/
// Decent, 2 approaches

/*
You are given a 0-indexed binary string s and two integers minJump and maxJump. In the beginning, you are standing at index 0, which is equal to '0'. 
You can move from index i to index j if the following conditions are fulfilled:

    i + minJump <= j <= min(i + maxJump, s.length - 1), and
    s[j] == '0'.

Return true if you can reach index s.length - 1 in s, or false otherwise.

Example 1:
Input: s = "011010", minJump = 2, maxJump = 3
Output: true
Explanation:
In the first step, move from index 0 to index 3. 
In the second step, move from index 3 to index 5.

Example 2:
Input: s = "01101110", minJump = 2, maxJump = 3
Output: false

Constraints:
    2 <= s.length <= 105
    s[i] is either '0' or '1'.
    s[0] == '0'
    1 <= minJump <= maxJump < s.length
*/

// App 1 : DP
// TC : O(N)

/*
We use a DP + Sliding window approach to solve this problem:

1. We keep a count of the number of indices in a window of size maxJump-minJump from which we can reach current index 'i'.
2. We also decerement count if there was a possiblity to reach current index i from i-maxJump-1, as we can no longer jump 
   from that index to reach current 'i' as it's no longer a part of the sliding window.
3. Finally, for the current index i if the count > 0 , this means that there is atleast one way to reach from the window 
   (i-maxJump, i-minJump) to our i, so we set the dp[i] = 0 in this case, with the added check that s[i]=='0'.
*/

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) 
    {
        if(s.back() == '1')
            return false;
        
        vector<bool> dp(s.size(), false);
        dp[0] = true;
        
        int count = 0;
        for(int i = 1; i < s.size(); ++i)
        {
            count += i >= minJump ? dp[i-minJump] : 0;
            count -= i > maxJump ? dp[i-maxJump-1] : 0;
            
            if(count > 0 && s[i] == '0')
                dp[i] = true;
        }
        if(dp.back())
            return true;
        return false;
    }
};

// App 2 : Binary Search
// TC : O(N log(N))

class Solution {
public:
    vector<int> index;
    
    bool can(int low, int high) // can we get previous index from which we can jump to current index
    {
        if(high < 0)
            return false;
        low = max(low, 0);
        
        int l = 0, r = index.size()-1, mid;
        
        while(r-l > 1)
        {
            mid = (r+l)/2;
            
            if(index[mid] >=low && index[mid] <= high)
                return true;
            
            if(index[mid] < low)
                l = mid;
            else
                r = mid;
        }
        if(index[l] >= low && index[l] <= high)
            return true;
        if(index[r] >= low && index[r] <= high)
            return true;
        return false;
    }
    
    bool canReach(string s, int minJump, int maxJump) 
    {
        if(s[0] != '0' || s.back() != '0')
            return false;
        
        index.push_back(0);
        for(int i = 1; i < s.size(); ++i)    
            if(s[i] == '0' && can(i-maxJump, i-minJump))
                index.push_back(i);
        
        if(index.back() == s.size()-1)
            return true;
        
        return false;
    }
};
