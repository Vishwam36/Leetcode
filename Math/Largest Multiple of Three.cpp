// By Vishwam Shriram Mundada
// https://leetcode.com/problems/largest-multiple-of-three/
// Lengthy implementation

/*
Given an integer array of digits, return the largest multiple of three that can be formed by concatenating some of the given digits in any order.

Since the answer may not fit in an integer data type, return the answer as a string.

If there is no answer return an empty string.

Example 1:
Input: digits = [8,1,9]
Output: "981"

Example 2:
Input: digits = [8,6,7,1,0]
Output: "8760"

Example 3:
Input: digits = [1]
Output: ""

Example 4:
Input: digits = [0,0,0,0,0,0]
Output: "0"

Constraints:
    1 <= digits.length <= 10^4
    0 <= digits[i] <= 9
    The returning answer must not contain unnecessary leading zeros.
*/

/*
HINT :
-> ans string has all digits in descending order
-> sum = sum of all digits
-> There are 3 possibilities
-> Case : sum % 3 == 0
   Then return string as it is
-> Case : sum % 3 == 1
   Remove smallest digit s.t digit % 3 == 1
   If such digit is not found then we have to find 2 smallest digits s.t digit % 3 == 2
   Else return ""
-> Case : sum % 3 == 2
   Remove smallest digit s.t digit % 3 == 2
   If such digit is not found then we have to find 2 smallest digits s.t digit % 3 == 1
   Else return ""
   
-> These are the only cases and its just implementation
-> I dont know why DP is written in related topics
*/

class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) 
    {
        string ans;
        sort(digits.begin(), digits.end(), greater<>());
        int sum = 0;
        for(int d : digits)
        {
            ans += to_string(d);
            sum += d;
        }
        
        while(ans[0] == '0' && ans.size() > 1) // remove redundant 0s
            ans.erase(ans.begin());
        
        if(sum % 3 == 0)
            return ans;
        
        if(sum % 3 == 1)
        {
            string s = ans;
            for(int i = ans.size()-1; i >= 0; --i)
            {
                if((s[i]-'0') % 3 == 1)
                {
                    s.erase(i, 1);
                    return s;
                }
            }
            
            int i1 = -1, i2 = -1;
            for(int i = ans.size()-1; i >= 0; --i)
            {
                if(i1 == -1 && i2 == -1 && (s[i]-'0') % 3 == 2)
                    i1 = i;
                
                else if(i2 == -1 && i1 != -1 && (s[i]-'0') % 3 == 2)
                    i2 = i;
                
                else if(i1 != -1 && i2 != -1)
                    break;
            }
            
            if(i1 != -1 && i2 != -1)
            {
                s.erase(i1, 1);
                s.erase(i2, 1);
                return s;
            }
            return "";
        }
        
        if(sum % 3 == 2)
        {
            string s = ans;
            for(int i = ans.size()-1; i >= 0; --i)
            {
                if((ans[i]-'0') % 3 == 2)
                {
                    s.erase(i, 1);
                    return s;
                }
            }
            
            int i1 = -1, i2 = -1;
            for(int i = ans.size()-1; i >= 0; --i)
            {
                if(i1 == -1 && i2 == -1 && (ans[i]-'0') % 3 == 1)
                    i1 = i;
                
                else if(i2 == -1 && i1 != -1 && (ans[i]-'0') % 3 == 1)
                    i2 = i;
                
                else if(i1 != -1 && i2 != -1)
                    break;
            }
            
            if(i1 != -1 && i2 != -1)
            {
                s.erase(i1, 1);
                s.erase(i2, 1);
                return s;
            }
            return "";
        }
        return "";
    }
};
