// By Vishwam Shriram Mundada
// https://leetcode.com/problems/create-maximum-number/
// Good variety

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        int n = nums1.size(), m = nums2.size();
        vector<int> ans(k, INT_MIN);
        
        for(int i = max(0, k-m); i <= min(k, n); ++i)
        {
            vector<int> a = extract(nums1, i);
            vector<int> b = extract(nums2, k-i);
            vector<int> ab = merge(a, b);
            ans = max(ans, ab);
        }
        return ans;
    }
    
    vector<int> extract(vector<int> &v, int k)
    {
        vector<int> ans;
        
        for(int i = 0; i < v.size(); ++i)
        {
            while(ans.size() && v.size()-i > k-ans.size() && ans.back() < v[i])
                ans.pop_back();
            
            if(ans.size() < k)
                ans.push_back(v[i]);
        }
        return ans;
    }
    
    vector<int> merge(vector<int> &v1, vector<int> &v2)
    {
        vector<int> ans;
        
        while(v1.size() && v2.size())
        {
            if(v1 > v2)
            {
                ans.push_back(v1[0]);
                v1.erase(v1.begin());
            }
            else
            {
                ans.push_back(v2[0]);
                v2.erase(v2.begin());
            }
        }
        
        while(v1.size())
        {
            ans.push_back(v1[0]);
            v1.erase(v1.begin());
        }
        
        while(v2.size())
        {
            ans.push_back(v2[0]);
            v2.erase(v2.begin());
        }
        
        return ans;
    }
};
