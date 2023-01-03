// https://leetcode.com/problems/rotate-function/description/
// Decent

class Solution {
public:
    int maxRotateFunction(vector<int>& v) 
    {
        int n = v.size(), sum = 0, ans = 0, simpleSum = 0;
        for(int i = 0; i < n; ++i)
        {
            simpleSum += v[i];
            sum += v[i] * i;
            ans = sum;
        }

        for(int i = 1; i < n; ++i)
        {
            sum += simpleSum - v[n-i] * n;
            ans = max(ans, sum);
        }
        return ans;
    }
};
