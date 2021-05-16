// By Vishwam Shriram Mundada
// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/
// Decent

/*
Given a binary string s, return the minimum number of character swaps to make it alternating, or -1 if it is impossible.
The string is called alternating if no two adjacent characters are equal. For example, the strings "010" and "1010" are alternating, while the string "0100" is not.
Any two characters may be swapped, even if they are not adjacent.

Example 1:
Input: s = "111000"
Output: 1
Explanation: Swap positions 1 and 4: "111000" -> "101010"
The string is now alternating.

Example 2:
Input: s = "010"
Output: 0
Explanation: The string is already alternating, no swaps are needed.

Example 3:
Input: s = "1110"
Output: -1

Constraints:
1 <= s.length <= 1000
s[i] is either '0' or '1'.
*/

class Solution {
public:
    int findAns(string s, string s1)
    {
        int ans = 0;
        for(int i = 0; i < s.size(); ++i)
            if(s1[i] != s[i])
                ans++;
        
        return ans;
    }
    
    int minSwaps(string s) 
    {
        int n = s.size(), zeros = 0, ones = 0;
        
        for(int i = 0; i < n; ++i)
            if(s[i] == '0')
                zeros++;
            else
                ones++;
        
        if(abs(zeros-ones) > 1)
            return -1;
        
        string s1(n, '0'), s2(n, '0');
        
        for(int i = 0; i < n; ++i)
        {
            if(i % 2 == 0)
            {
                s1[i] = '0';
                s2[i] = '1';
            }
            else
            {
                s1[i] = '1';
                s2[i] = '0';
            }
        }
        
        if(zeros > ones)
            return findAns(s, s1)/2;
        
        if(ones > zeros)
            return findAns(s, s2)/2;
        
        return min(findAns(s, s1), findAns(s, s2))/2;
    }
};
