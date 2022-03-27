// By Vishwam Shriram Mundada
// https://leetcode.com/problems/find-palindrome-with-fixed-length/
// Decent

/*
Given an integer array queries and a positive integer intLength, return an array answer where answer[i] is either the queries[i]th 
smallest positive palindrome of length intLength or -1 if no such palindrome exists.

A palindrome is a number that reads the same backwards and forwards. Palindromes cannot have leading zeros.

Example 1:
Input: queries = [1,2,3,4,5,90], intLength = 3
Output: [101,111,121,131,141,999]
Explanation:
The first few palindromes of length 3 are:
101, 111, 121, 131, 141, 151, 161, 171, 181, 191, 201, ...
The 90th palindrome of length 3 is 999.

Example 2:
Input: queries = [2,4,6], intLength = 4
Output: [1111,1331,1551]
Explanation:
The first six palindromes of length 4 are:
1001, 1111, 1221, 1331, 1441, and 1551.

Constraints:
    1 <= queries.length <= 5 * 10^4
    1 <= queries[i] <= 10^9
    1 <= intLength <= 15
*/

class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int l) 
    {
        string s((l+1)/2, '9');
        int maxLim = stoll(s);
        
        vector<long long> ans(queries.size(), -1);
        
        for(int i = 0; i < queries.size(); ++i)
        {
            long long q = queries[i];
            long long half = pow(10, (l-1)/2);
            half += (q-1);
                
            if(half > maxLim)
                continue;
            
            string s = to_string(half);
            string ss = s;
            
            if(l % 2 == 1)
                ss.pop_back();
            
            reverse(ss.begin(), ss.end());
            s += ss;
            ans[i] = stoll(s);
        }
        
        return ans;
    }
};
