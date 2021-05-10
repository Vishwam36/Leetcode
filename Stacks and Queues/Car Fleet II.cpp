// By Vishwam Shriram Mundada
// https://leetcode.com/problems/car-fleet-ii/
// Good conceptual question
// Good Explanation, Ref : https://www.youtube.com/watch?v=SVW1bD_PN6A&ab_channel=CherryCoding%5BIIT-G%5D

/*
There are n cars traveling at different speeds in the same direction along a one-lane road. You are given an array cars of length n,
where cars[i] = [positioni, speedi] represents:
positioni is the distance between the ith car and the beginning of the road in meters. It is guaranteed that positioni < positioni+1.
speedi is the initial speed of the ith car in meters per second.
For simplicity, cars can be considered as points moving along the number line. Two cars collide when they occupy the same position. 
Once a car collides with another car, they unite and form a single car fleet. 
The cars in the formed fleet will have the same position and the same speed, which is the initial speed of the slowest car in the fleet.

Return an array answer, where answer[i] is the time, in seconds, at which the ith car collides with the next car, 
or -1 if the car does not collide with the next car. Answers within 10-5 of the actual answers are accepted.

Example 1:
Input: cars = [[1,2],[2,1],[4,3],[7,2]]
Output: [1.00000,-1.00000,3.00000,-1.00000]
Explanation: After exactly one second, the first car will collide with the second car, and form a car fleet with speed 1 m/s.
After exactly 3 seconds, the third car will collide with the fourth car, and form a car fleet with speed 2 m/s.

Example 2:
Input: cars = [[3,4],[5,4],[6,3],[9,1]]
Output: [2.00000,1.00000,1.50000,-1.00000]

Constraints:
1 <= cars.length <= 105
1 <= positioni, speedi <= 106
positioni < positioni+1
*/

class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) 
    {
        // notice than when a car collides with next car then next cars speed is obviously slower
        // hence they combine and new combinaion speed is same as next car and location is also same as next
        // its like wiping out current car and continuing next car as it was
        int n = cars.size();
        vector<double> ans(n, -1);
        stack<int> st; // stores indexes of the next cars who are potential colliders
        for(int i = n-1; i >= 0; --i)
        {
            // if the cars in stack (who were potential colliders) are no more going to collide (i.e speed is greater or equal than current) then pop
            while(!st.empty() && cars[st.top()][1] >= cars[i][1])
                st.pop();
            
            while(!st.empty())
            {
                double time = (double)(cars[st.top()][0] - cars[i][0]) / (cars[i][1] - cars[st.top()][1]);
                
                // if condition is true then curr car can surely collide and we got ans hence break
                if(ans[st.top()] == -1 || ans[st.top()] >= time)
                {
                    ans[i] = time;
                    break;
                }
                // else pop
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
