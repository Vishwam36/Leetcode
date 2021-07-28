// By Vishwam Shriram Mundada
// https://leetcode.com/problems/range-sum-query-mutable/
// Standard

/*
Given an integer array nums, handle multiple queries of the following types:

Update the value of an element in nums.
Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
void update(int index, int val) Updates the value of nums[index] to be val.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

Example 1:
Input
["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
Output
[null, 9, null, 8]

Explanation
NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
numArray.update(1, 2);   // nums = [1, 2, 5]
numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8
 
Constraints:
1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
0 <= index < nums.length
-100 <= val <= 100
0 <= left <= right < nums.length
At most 3 * 104 calls will be made to update and sumRange.
*/

class NumArray {
public:
    int n;
    vector<int> nums;
    vector<int> tree;
    
    NumArray(vector<int>& nums) 
    {
        this->nums = nums;
        this->n = nums.size();
        tree = vector<int>(4*n);
        
        makeTree(1, 0, n-1);
    }
    
    int makeTree(int root, int st, int end)
    {
        if(st == end)
            return tree[root] = nums[st];
        
        int mid = (st+end)/2;
        int left = makeTree(2*root, st, mid);
        int right = makeTree(2*root + 1, mid+1, end);
        
        return tree[root] = left + right;
    }
    
    void update(int index, int val)
    {
        int diff = val - nums[index];
        nums[index] = val;
        updateRec(1, 0, n-1, index, diff);
    }
    
    void updateRec(int root, int st, int end, int index, int diff)
    {
        if(index < st || index > end)
            return;
        
        tree[root] += diff;
        
        if(st == end)
            return;
        
        int mid = (st+end)/2;
        updateRec(2*root, st, mid, index, diff);
        updateRec(2*root + 1, mid+1, end, index, diff);
    }
    
    int sumRange(int left, int right) 
    {
        return sumRangeRec(1, 0, n-1, left, right);
    }
    
    int sumRangeRec(int root, int st, int end, int l, int r)
    {
        if(r < st || l > end)
            return 0;
        
        if(st >= l && end <= r)
            return tree[root];
        
        int mid = (st+end)/2;
        int left = sumRangeRec(2*root, st, mid, l, r);
        int right = sumRangeRec(2*root + 1, mid+1, end, l, r);
        
        return left + right;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
