// By Vishwam Shriram Mundada
// https://leetcode.com/problems/fruit-into-baskets/
// Decent

/*
You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the 
type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit
in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.

Example 1:
Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.

Example 2:
Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].

Example 3:
Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].

Example 4:
Input: fruits = [3,3,3,1,2,1,1,2,3,3,4]
Output: 5
Explanation: We can pick from trees [1,2,1,1,2].
 
Constraints:
1 <= fruits.length <= 10^5
0 <= fruits[i] < fruits.length
*/

class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
        int n = fruits.size();
        int l = 0, r = 0, ans = 0;
        unordered_map<int, int> m; // m[fruit] -> count
        
        while(r < n)
        {
            while(r < n && m.size() <= 2)
            {
                if(m.find(fruits[r]) != m.end()) // if already present then keep it
                {
                    m[fruits[r]]++;
                    r++;
                }
                else if(m.size() == 2) // if size is already 2 and fruit is of new variety
                {
                    break;
                }
                else // else add normally
                {
                    m[fruits[r]]++;
                    r++;
                }
            }
            
            ans = max(ans, r-l);
            
            while(m.size() >= 2) // remove 1 fruit
            {
                m[fruits[l]]--; 
                
                if(m[fruits[l]] == 0)
                    m.erase(m.find(fruits[l]));
                
                ++l;
            }
        }
        
        return ans;
    }
};
