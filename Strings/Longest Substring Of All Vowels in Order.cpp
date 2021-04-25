// By Vishwam Shriram Mundada
// https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/submissions/
// Decent
/*
A string is considered beautiful if it satisfies the following conditions:

Each of the 5 English vowels ('a', 'e', 'i', 'o', 'u') must appear at least once in it.
The letters must be sorted in alphabetical order (i.e. all 'a's before 'e's, all 'e's before 'i's, etc.).
For example, strings "aeiou" and "aaaaaaeiiiioou" are considered beautiful, but "uaeio", "aeoiu", and "aaaeeeooo" are not beautiful.

Given a string word consisting of English vowels, return the length of the longest beautiful substring of word. If no such substring exists, return 0.
A substring is a contiguous sequence of characters in a string.

Example 1:
Input: word = "aeiaaioaaaaeiiiiouuuooaauuaeiu"
Output: 13
Explanation: The longest beautiful substring in word is "aaaaeiiiiouuu" of length 13.

Example 2:
Input: word = "aeeeiiiioooauuuaeiou"
Output: 5
Explanation: The longest beautiful substring in word is "aeiou" of length 5.

Example 3:
Input: word = "a"
Output: 0
Explanation: There is no beautiful substring, so return 0.

Constraints:
1 <= word.length <= 5 * 105
word consists of characters 'a', 'e', 'i', 'o', and 'u'.
*/

class Solution {
public:
    char nextVovel(char c)
    {
        if(c == 'a')
            return 'e';
        if(c == 'e')
            return 'i';
        if(c == 'i')
            return 'o';
        
        return 'u';
    }
        
    int longestBeautifulSubstring(string word) 
    {
        bool covered = 0;
        char pre = 'a', next = 'a';
        int ans = 0, finalAns = 0;
        
        for(int i = 0; i < word.size(); ++i)
        {
            if(word[i] == next)
            {
                ans++;
                if(next == 'u')
                {
                    covered = 1;
                    finalAns = max(finalAns , ans);
                }
                pre = next;
                next = nextVovel(word[i]);
            }
            else if(word[i] == pre)
            {
                next = nextVovel(word[i]);
                ans++;
            }
            else
            {
                ans = 0;
                if(word[i] == 'a')
                    ans++;
                
                pre = 'a';
                next = 'a';
            }
        }
        
        if(covered == 0)
            return 0;
        
        return finalAns;
    }
};
