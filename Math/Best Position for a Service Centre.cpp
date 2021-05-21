// By Vishwam Shriram Mundada
// https://leetcode.com/problems/best-position-for-a-service-centre/
// V.Good, Math, ternary search
// REF : https://leetcode.com/problems/best-position-for-a-service-centre/discuss/737847/C%2B%2B-2-dim-ternary-search-with-a-proof-of-convergence-and-time-complexity-estimation

/*
A delivery company wants to build a new service centre in a new city. The company knows the positions of all the customers in this city on a 
2D-Map and wants to build the new centre in a position such that the sum of the euclidean distances to all customers is minimum.

Given an array positions where positions[i] = [xi, yi] is the position of the ith customer on the map, return the minimum sum of the 
euclidean distances to all customers.

In other words, you need to choose the position of the service centre [xcentre, ycentre] such that the following formula is minimized:
Answers within 10^-5 of the actual value will be accepted.

Example 1:
Input: positions = [[0,1],[1,0],[1,2],[2,1]]
Output: 4.00000
Explanation: As shown, you can see that choosing [xcentre, ycentre] = [1, 1] will make the distance to each customer = 1, the sum of all distances is 4 which is the minimum possible we can achieve.

Example 2:
Input: positions = [[1,1],[3,3]]
Output: 2.82843
Explanation: The minimum possible sum of distances = sqrt(2) + sqrt(2) = 2.82843

Example 3:
Input: positions = [[1,1]]
Output: 0.00000

Example 4:
Input: positions = [[1,1],[0,0],[2,0]]
Output: 2.73205
Explanation: At the first glance, you may think that locating the centre at [1, 0] will achieve the minimum sum, but locating it at [1, 0] will make the sum of distances = 3.
Try to locate the centre at [1.0, 0.5773502711] you will see that the sum of distances is 2.73205.
Be careful with the precision!

Example 5:
Input: positions = [[0,1],[3,2],[4,5],[7,6],[8,9],[11,1],[2,12]]
Output: 32.94036
Explanation: You can use [4.3460852395, 4.9813795505] as the position of the centre.

Constraints:
    1 <= positions.length <= 50
    positions[i].length == 2
    0 <= positions[i][0], positions[i][1] <= 100
*/

// HINT
/*
The target function is a sum of distances. A distance is a convex function, and a sum of convex functions is a convex function. Therefore, The target function is a convex function. It means if it has a local minimum, it is guaranteed to be the global minimum.

As the target function is a convex function, we can use a ternary-search-like approach. *

1. Divide the area into 9 rectangles (4 lines for each axis.)
2. Calculate the value for 16 points and find the point which gives the minimum value.
3. The global minimum value is inside the 4 rectangles around the point. so narrow down the searching area to it.

I noticed that the statement global minimum value is inside the 4 rectangles around the point is false. that's why we cannot use ternary-search-like approach only with condition that the target function is a convex function. the code below works fine basically (at least for prepared test cases) but we can find test cases which fail.

Note that If all the points are on a straight line, it is a line segment that gives the minimum value, not a point. For example, if the points are (0, 0), (1, 0), the line segment x in [0, 1], y = 0 gives the minumum value. However, in this case too, it's ok to assume that a point gives the minimum value because it can converge to any point on that line segment and the minimum value is same.

It's sufficient to end the search when both sides of the rectangle are less than 10^-7.
The two farthest points in the square with one side R are the two vertices on the diagonal, which are √2 R. N is the maximum 50, so the difference between the sums of the distances is at most 50√2 R. If R is less than 10^-7, then the difference between the sums is found to be less than 10^-5. No matter which point in the range we choose as the solution, and no matter which point in the range the true solution is, the error of the minimum value sought is less than 10^-5 is guaranteed.

For time complexity,

    each iteration: O(N * 4^2)
    one iteration reduces the search area to 4 / 9 (divided rectangle size is 1 / 9, and the next search area contains 4 rectangles around the minimum point)
    for worst case, search area should be reduced from 100^2 to (10^-7)^2, i.e. 1 / 10^18.
    the number of iteration is about log_{4/9}{10^-18}

therefore time complexity is about O(N * 4^2 * log_{4/9}{10^{-18}} = O(9N * 4^2 / log_{10}{3/2}).
*/

class Solution {
public:
    double EPSILON = 0.0000001, res = 1000000000000, res_x = 0, res_y = 0;
    double left = 100, right = 0, top = 0, bottom = 100;
    
    double distance(double x, double y, double x1, double y1)
    {
        return sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));
    }
    
    void modified_ternary_search(vector<vector<int>>& positions)
    {
        if(left == right && bottom == top)
            res = 0;
        
        while(abs(top-bottom) > EPSILON || abs(right-left) > EPSILON)
        {   
            double dx = (right-left)/3;
            double dy = (top-bottom)/3;
            
            for(int i = 0; i <= 3; ++i)
            {
                for(int j = 0; j <= 3; ++j)
                {
                    double x = left + (double)i * dx;
                    double y = bottom + (double)j * dy;
        
                    double dist = 0;
                    for(auto pos : positions)
                    {
                       dist += distance(x, y, pos[0], pos[1]);
                    }
                    if(dist < res)
                    {
                        res = dist;
                        res_x = x;
                        res_y = y;
                    }
                }
            }
            // we calculate x and y for each point and there may be a floating point precision error.
	        // expanding the area a little may be necessary to prevent the area near the boundary from being dropped.
            left = res_x - 1.0001 * dx;
            right = res_x + 1.0001 * dx;
            top = res_y + 1.0001 * dy;
            bottom = res_y - 1.0001 * dy;
        }
    }
    
    double getMinDistSum(vector<vector<int>>& positions) 
    {
        for(auto pos : positions)
        {
            left = min(left, (double)pos[0]);
            right = max(right, (double)pos[0]);
            top = max(top, (double)pos[1]);
            bottom = min(bottom, (double)pos[1]);
        }
        
        modified_ternary_search(positions);        
        return res;
    }
};
