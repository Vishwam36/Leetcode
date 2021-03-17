// By Vishwam Shriram Mundada
// https://leetcode.com/problems/shuffle-the-array/
// If no extra space allowed then good question

void reverse(vector<int> &a, int l, int r)
{
    int m  = (r-l+1)/2;
    
    for(int i = 0; i < m; ++i)
        swap(a[l+i], a[r-i]);
}

void shuffleUtil(vector<int> &a, int st, int end)
{
    int l = end-st+1;
    
    if(l <= 2)
        return;
    
    int mid = st + l/2;
    
    // devides array into two even haves
	// doesn't matter whether you increase mid or decrease
    if(l % 4 > 0)
        mid++;
    
    int mid1 = st + (mid-st)/2;
    int mid2 = mid + (end-mid+1)/2;
    
    reverse(a, mid1, mid2-1);
    reverse(a, mid1, mid-1);
    reverse(a, mid, mid2-1);
    
    shuffleUtil(a, st, mid-1);
    shuffleUtil(a, mid, end);
}

class Solution {
public:
    vector<int> shuffle(vector<int>& a, int n) 
    {	
        shuffleUtil(a, 0, 2*n - 1);
        return a;
    }
};
