// By Vishwam Shriram Mundada
// https://leetcode.com/problems/minimum-space-wasted-from-packaging/
// Good question

/*
You have n packages that you are trying to place in boxes, one package in each box. There are m suppliers that each produce boxes of different sizes (with infinite supply).
A package can be placed in a box if the size of the package is less than or equal to the size of the box.

The package sizes are given as an integer array packages, where packages[i] is the size of the ith package. The suppliers are given as a 2D integer array boxes, 
where boxes[j] is an array of box sizes that the jth supplier produces.

You want to choose a single supplier and use boxes from them such that the total wasted space is minimized. For each package in a box, we define the space wasted 
to be size of the box - size of the package. The total wasted space is the sum of the space wasted in all the boxes.

For example, if you have to fit packages with sizes [2,3,5] and the supplier offers boxes of sizes [4,8], you can fit the packages of size-2 and size-3 into two boxes 
of size-4 and the package with size-5 into a box of size-8. This would result in a waste of (4-2) + (4-3) + (8-5) = 6.
Return the minimum total wasted space by choosing the box supplier optimally, or -1 if it is impossible to fit all the packages inside boxes. Since the answer may be large,
return it modulo 109 + 7.

Example 1:
Input: packages = [2,3,5], boxes = [[4,8],[2,8]]
Output: 6
Explanation: It is optimal to choose the first supplier, using two size-4 boxes and one size-8 box.
The total waste is (4-2) + (4-3) + (8-5) = 6.

Example 2:
Input: packages = [2,3,5], boxes = [[1,4],[2,3],[3,4]]
Output: -1
Explanation: There is no box that the package of size 5 can fit in.

Example 3:
Input: packages = [3,5,8,10,11,12], boxes = [[12],[11,9],[10,5,14]]
Output: 9
Explanation: It is optimal to choose the third supplier, using two size-5 boxes, two size-10 boxes, and two size-14 boxes.
The total waste is (5-3) + (5-5) + (10-8) + (10-10) + (14-11) + (14-12) = 9.

Constraints:
n == packages.length
m == boxes.length
1 <= n <= 105
1 <= m <= 105
1 <= packages[i] <= 105
1 <= boxes[j].length <= 105
1 <= boxes[j][k] <= 105
sum(boxes[j].length) <= 105
The elements in boxes[j] are distinct.
*/

class Solution {
public:
    int countPackages(vector<int> &p, int topi)
    {
        int l = 0, r = p.size()-1, mid;
        
        while(r-l > 1)
        {
            mid = (l+r)/2;
            
            if(p[mid] <= topi)
                l = mid;
            else
                r = mid;
        }
        if(p[r] <= topi)
            return r+1;
        if(p[l] <= topi)
            return l+1;
        return 0;
    }
    
    int minWastedSpace(vector<int>& pack, vector<vector<int>>& boxes) 
    {
        long long ans = LLONG_MAX;
        sort(pack.begin(), pack.end());
        
        vector<long long> pre(pack.size(), 0); // presum of packs, will tell how much packspace we took (to be subtracted from boxspace took)
        pre[0] = pack[0];
        for(int i = 1; i < pack.size(); ++i)
            pre[i] = pack[i] + pre[i-1];
        
        for(auto b : boxes)
        {
            sort(b.begin(), b.end());
            
            int totalPicked = 0;
            long long currAns = 0;
            
            for(int topi : b)
            {
                int cnt = countPackages(pack, topi); // maximum number of packs current topi(box) could take
                
                int pickedByCurr = cnt-totalPicked; // actual packs taken by currnt topi
                
                totalPicked += pickedByCurr;
                
                if(totalPicked == 0)
                    continue;
                else if(totalPicked == pickedByCurr)
                    currAns -= pre[totalPicked-1];
                else
                    currAns -= pre[totalPicked-1] - pre[totalPicked-1-pickedByCurr];
                
                currAns += (long long)pickedByCurr * topi;
            }
            
            if(totalPicked == pack.size()) // if we could take all packs
                ans = min(ans, currAns);
        }
        if(ans == LLONG_MAX)
            return -1;
        
        return ans % 1000000007;
    }
};
