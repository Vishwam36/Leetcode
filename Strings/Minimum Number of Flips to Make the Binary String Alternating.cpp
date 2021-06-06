// By Vishwam Shriram Mundada
// https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/
// Good question

/*
You are given a binary string s. You are allowed to perform two types of operations on the string in any sequence:
    Type-1: Remove the character at the start of the string s and append it to the end of the string.
    Type-2: Pick any character in s and flip its value, i.e., if its value is '0' it becomes '1' and vice-versa.

Return the minimum number of type-2 operations you need to perform such that s becomes alternating.

The string is called alternating if no two adjacent characters are equal.

    For example, the strings "010" and "1010" are alternating, while the string "0100" is not.

Example 1:
Input: s = "111000"
Output: 2
Explanation: Use the first operation two times to make s = "100011".
Then, use the second operation on the third and sixth elements to make s = "101010".

Example 2:
Input: s = "010"
Output: 0
Explanation: The string is already alternating.

Example 3:
Input: s = "1110"
Output: 1
Explanation: Use the second operation on the second element to make s = "1010".

Constraints:
    1 <= s.length <= 105
    s[i] is either '0' or '1'.
*/

/*
HINT :
    For the 1st operation, we can simply do s += s to append the whole string to the end.
    then we make two different string with the same length by 01 and 10 alternative. for example: s = 11100
        s = 1110011100
        s1= 1010101010
        s2= 0101010101
    finally, use sliding window（size n）to compare s to both s1 and s2.
    why we can double s to fullfil the first operation, let's look at the same example s = 11100:`
        double s: 1110011100
        size n window: |11100|11100 ==> 1|11001|1100 ==> 11|10011|100 and so on, when we move one step of the sliding window, 
        it is the same to append 1 more element from beginning.

    TC : O(N)
    SC : O(N)
*/

class Solution {
public:
    int minFlips(string s) 
    {
        int n = s.size();
        s += s;
        string s1, s2;
        
        for(int i = 0; i < s.size(); ++i)
        {
            s1 += i % 2 ? "1" : "0";
            s2 += i % 2 ? "0" : "1";
        }
        
        int ans1 = 0, ans2 = 0, ans = INT_MAX;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] != s1[i])
                ans1++;
            if(s[i] != s2[i])
                ans2++;
            
            if(i >= n)
            {
                if(s[i-n] != s1[i-n])
                    ans1--;
                if(s[i-n] != s2[i-n])
                    ans2--;
            }
            
            if(i >= n-1)
                ans = min(ans, min(ans1, ans2));
        }
        return ans;
    }
};
