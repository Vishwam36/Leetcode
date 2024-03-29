// By Vishwam Shriram Mundada
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/109/backtracking/793/
// Easy

/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]

Constraints:
    0 <= digits.length <= 4
    digits[i] is a digit in the range ['2', '9'].
*/

class Solution {
public:
    map<char, vector<char> > m;
    void init()
    {
        m['2'] = {'a', 'b', 'c'};
        m['3'] = {'d', 'e', 'f'};
        m['4'] = {'g', 'h', 'i'};
        m['5'] = {'j', 'k', 'l'};
        m['6'] = {'m', 'n', 'o'};
        m['7'] = {'p', 'q', 'r', 's'};
        m['8'] = {'t', 'u', 'v'};
        m['9'] = {'w', 'x', 'y', 'z'};
    }
    
    vector<string> ans;
    
    void rec(int idx, string &digits, string &temp)
    {
        if(idx == digits.size())
        {
            if(temp != "")
                ans.push_back(temp);
            return;
        }
        
        char ch = digits[idx];
        
        for(auto letter : m[ch])
        {
            temp.push_back(letter);
            rec(idx+1, digits, temp);
            temp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) 
    {
        init();
        string temp;
        rec(0, digits, temp);
        return ans;
    }
};
