// By Vishwam Shriram Mundada
// https://leetcode.com/problems/count-of-smaller-numbers-after-self/
// Good question, mergeSort concept

/*
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to 
the right of nums[i].

Example 1:
Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.

Example 2:
Input: nums = [-1]
Output: [0]

Example 3:
Input: nums = [-1,-1]
Output: [0,0]
 
Constraints:
1 <= nums.length <= 10^5
-104 <= nums[i] <= 10^4
*/

// REF : https://www.youtube.com/watch?v=ffbwCfJ2Qjw&t=5s&ab_channel=happygirlzt

class Item
{
public:
    
    int val;
    int idx;
    
    Item() {}
    
    Item(int v, int i)
    {
        this->val = v;
        this->idx = i;
    }
};

class Solution {
public:
    vector<int> ans;
    
    void merge(vector<Item> &arr, vector<Item> &l, vector<Item> &r)
    {
        int i = 0, j = 0, k = 0;
        int rightCounter = 0;
        
        while(i < l.size() && j < r.size())
        {
            if(l[i].val > r[j].val)
            {
                rightCounter++;
                arr[k++] = r[j++];
            }
            else
            {
                ans[l[i].idx] += rightCounter;
                arr[k++] = l[i++];
            }
        }
        
        while(i < l.size())
        {
            ans[l[i].idx] += rightCounter;
            arr[k++] = l[i++];
        }
        
        while(j < r.size())
        {
            arr[k++] = r[j++];
        }
    }
    
    void mergeSort(vector<Item> &arr)
    {
        int n = arr.size();
        if(n <= 1)
            return;
        
        int mid = n/2;
        vector<Item> l(mid);
        vector<Item> r(n-mid);
        
        for(int i = 0; i < mid; ++i)
            l[i] = arr[i];
        for(int i = mid; i < n; ++i)
            r[i-mid] = arr[i];
        
        mergeSort(l);
        mergeSort(r);
        merge(arr, l, r);
    }
    
    vector<int> countSmaller(vector<int>& nums)
    {
        ans = vector<int>(nums.size(), 0);
        
        vector<Item> arr(nums.size());
        for(int i = 0; i < nums.size(); ++i)
            arr[i] = Item(nums[i], i);
        
        mergeSort(arr);
        return ans;
    }
};
