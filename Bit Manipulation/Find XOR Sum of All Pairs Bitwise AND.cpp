// By Vishwam Shriram Mundada
// https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and/
// Decent, little calculation

class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) 
    {
        int a1 = 0, a2 = 0;
        for(int i = 0; i < arr1.size(); ++i)
            a1 = a1 ^ arr1[i];
        
        for(int i = 0; i < arr2.size(); ++i)
            a2 = a2 ^ arr2[i];
        
        return a1 & a2;
    }
};
