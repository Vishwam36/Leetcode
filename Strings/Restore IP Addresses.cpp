// By Vishwam Shriram Mundada
// https://leetcode.com/problems/restore-ip-addresses/
// Decent, Brute Force

/*
Given a string s containing only digits, return all possible valid IP addresses that can be obtained from s. You can return them in any order.

A valid IP address consists of exactly four integers, each integer is between 0 and 255, separated by single dots and cannot have leading zeros. For example, "0.1.2.201" 
and "192.168.1.1" are valid IP addresses and "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses. 

Example 1:
Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]

Example 2:
Input: s = "0000"
Output: ["0.0.0.0"]

Example 3:
Input: s = "1111"
Output: ["1.1.1.1"]

Example 4:
Input: s = "010010"
Output: ["0.10.0.10","0.100.1.0"]

Example 5:
Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]

Constraints:
0 <= s.length <= 3000
s consists of digits only.
*/

class Solution {
public:
    int lastDot(string &temp) // returns the index of latest dot
    {
        for(int i = temp.size()-1; i >= 0; --i)
            if(temp[i] == '.')
                return i;
        return 0;
    }
    
    bool isValid(string &s) // checks if IP address is avlid or not
    {
        int i = 0;
        while(i < s.size())
        {
            string num;
            while(i < s.size() && s[i] != '.')
            {
                num.push_back(s[i]);
                ++i;
            }
            if(num.size() > 1 && num[0] == '0')
                return false;
            if(stoi(num) > 255)
                return false;
            ++i;
        }
        return true;
    }
    
    vector<string> restoreIpAddresses(string s)
    {
        set<string> ans;
        
        if(s.size() > 12 || s.size() < 4)
            return vector<string> (ans.begin(), ans.end());
        
        // check all possibilities of inserting 3 dots
        for(int i = 1; i <= 3; ++i)
        {
            s.insert(i, ".");
            int ld1 = lastDot(s);
            for(int j = ld1+2; j <= ld1+4 && j < s.size(); ++j)
            {
                s.insert(j, ".");
                int ld2 = lastDot(s);
                for(int k = ld2+2; k <= ld2+4 && k < s.size(); ++k)
                {
                    s.insert(k, ".");
                    
                    if(isValid(s))
                        ans.insert(s);
                    
                    s.erase(k, 1);
                }
                s.erase(j, 1);
            }
            s.erase(i, 1);
        }
        return vector<string> (ans.begin(), ans.end());
    }
};
