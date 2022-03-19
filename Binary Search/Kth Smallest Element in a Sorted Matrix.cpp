// By Vishwam Shriram Mundada
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/120/sorting-and-searching/858/
// Good

/*
Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n2).

Example 1:
Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13

Example 2:
Input: matrix = [[-5]], k = 1
Output: -5

Constraints:
    n == matrix.length == matrix[i].length
    1 <= n <= 300
    -109 <= matrix[i][j] <= 109
    All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
    1 <= k <= n^2
*/


// TC : O(N logN)
// SC : O(N)
// Priority queue

class Solution {
public:
    #define pip pair<int, pair<int, int> > 
    int n;
    int kthSmallest(vector<vector<int>>& mat, int k)
    {
        n = mat.size();
        priority_queue<pip, vector<pip>, greater<pip> > pq;
        for(int i = 0; i < n; ++i)
            pq.push({mat[i][0], {i,0}});
        
        int ans;
        while(k--)
        {
            pip p = pq.top(); pq.pop();
            ans = p.first;
            int ele = p.first;
            int i = p.second.first;
            int j = p.second.second;
            
            if(j+1 < n)
                pq.push({mat[i][j+1], {i, j+1}});
        }
        
        return ans;
    }
};


// TC : O((N+M) log 10^9)
// SC : O(1)
// Binary Search

class Solution {
public:
    int n;
    
    int countLessOrEqual(vector<vector<int>>& mat, int ele)
    {
        int c = n-1, ans = 0;
        for(int r = 0; r < n; ++r)
        {
            while(c >= 0 && mat[r][c] > ele)
                c--;
            
            ans += (c+1);
        }
        return ans;
    }
    
    int kthSmallest(vector<vector<int>>& mat, int k)
    {
        n = mat.size();
        int l = mat[0][0], r = mat[n-1][n-1], ans;
        while(r >= l)
        {
            int mid = (l+r)/2;
            if(countLessOrEqual(mat, mid) >= k)
            {
                ans = mid;
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return ans;
    }
};
