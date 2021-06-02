// By Vishwam Shriram Mundada
// https://leetcode.com/problems/number-of-days-between-two-dates/
// Decent

/*
Write a program to count the number of days between two dates.

The two dates are given as strings, their format is YYYY-MM-DD as shown in the examples.

Example 1:
Input: date1 = "2019-06-29", date2 = "2019-06-30"
Output: 1

Example 2:
Input: date1 = "2020-01-15", date2 = "2019-12-31"
Output: 15

Constraints:
    The given dates are valid dates between the years 1971 and 2100.
*/

class Solution {
public:
    bool leap(int year)
    {
        if(((year%4) == 0 && (year%100 != 0)) || (year%400 == 0))
            return true;
        
        return false;
    }
    
    int count_leap(int year)
    {
        int ans = year / 4;
        ans -= year / 100;
        ans += year / 400;
        return ans;
    }
    
    int daysBetweenDates(string d1, string d2) 
    {
        int m[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int y1 = stoll(d1.substr(0, 4));
        int y2 = stoll(d2.substr(0, 4));
        int m1 = stoll(d1.substr(5, 2));
        int m2 = stoll(d2.substr(5, 2));
        int day1 = stoll(d1.substr(8));
        int day2 = stoll(d2.substr(8));
        
        int a = y1 * 365 + count_leap(y1);
        int b = y2 * 365 + count_leap(y2);
        
        if(leap(y1) && m1 <= 2 && day1 <= 28)
            a--;
        if(leap(y2) && m2 <= 2 && day2 <= 28)
            b--;
        
        int month = 1;
        while(month != m1)
            a += m[month++];
        
        a += day1;
        
        month = 1;
        while(month != m2)
            b += m[month++];
        
        b += day2;
        
        return abs(a-b);
    }
};
