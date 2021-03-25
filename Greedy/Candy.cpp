// By Vishwam Shriram Mundada
// https://leetcode.com/problems/candy/
// Decent

class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        int ans  = 0;
        vector<int> left(ratings.size(), 1);
        vector<int> right(ratings.size(), 1);
        
        for(int i = 0; i < ratings.size()-1; ++i)
            if(ratings[i+1] > ratings[i])
                left[i+1] = left[i]+1;
        
        for(int i = ratings.size()-1; i > 0; --i)
            if(ratings[i-1] > ratings[i])
                right[i-1] = right[i]+1;
        
        for(int i = 0; i < ratings.size(); ++i)
            ans += max(left[i], right[i]);
        
        return ans;
    }
};
