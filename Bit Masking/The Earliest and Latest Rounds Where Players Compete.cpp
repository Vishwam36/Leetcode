// By Vishwam Shriram Mundada
// https://leetcode.com/problems/the-earliest-and-latest-rounds-where-players-compete/
// Good question

/*
There is a tournament where n players are participating. The players are standing in a single row and are numbered from 1 to n based on their initial standing 
position (player 1 is the first player in the row, player 2 is the second player in the row, etc.).

The tournament consists of multiple rounds (starting from round number 1). In each round, the ith player from the front of the row competes against the 
ith player from the end of the row, and the winner advances to the next round. When the number of players is odd for the current round, the player in the 
middle automatically advances to the next round.

    For example, if the row consists of players 1, 2, 4, 6, 7
        Player 1 competes against player 7.
        Player 2 competes against player 6.
        Player 4 automatically advances to the next round.

After each round is over, the winners are lined back up in the row based on the original ordering assigned to them initially (ascending order).

The players numbered firstPlayer and secondPlayer are the best in the tournament. They can win against any other player before they compete against each other. 
If any two other players compete against each other, either of them might win, and thus you may choose the outcome of this round.

Given the integers n, firstPlayer, and secondPlayer, return an integer array containing two values, the earliest possible round number and 
the latest possible round number in which these two players will compete against each other, respectively.

Example 1:
Input: n = 11, firstPlayer = 2, secondPlayer = 4
Output: [3,4]
Explanation:
One possible scenario which leads to the earliest round number:
First round: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
Second round: 2, 3, 4, 5, 6, 11
Third round: 2, 3, 4
One possible scenario which leads to the latest round number:
First round: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
Second round: 1, 2, 3, 4, 5, 6
Third round: 1, 2, 4
Fourth round: 2, 4

Example 2:
Input: n = 5, firstPlayer = 1, secondPlayer = 5
Output: [1,1]
Explanation: The players numbered 1 and 5 compete in the first round.
There is no way to make them compete in any other round.

Constraints:
    2 <= n <= 28
    1 <= firstPlayer < secondPlayer <= n
*/

class Solution {
public:
    int min_ans = INT_MAX, max_ans = INT_MIN;
    
    void rec(int mask, int i, int j, int n, int round, int fp, int sp)
    {
        if(i >= j) // round is completed and no more players can compete. So restart round
        {
            rec(mask, 0, n-1, n, round+1, fp, sp);
            return;
        }
        if(i == fp && j == sp) // first and second are competing
        {
            max_ans = max(max_ans, round);
            min_ans = min(min_ans, round);
            return;
        }
        if(((1 << i) & (mask)) == 0) // i is out
        {
            rec(mask, i+1, j, n, round, fp, sp);
            return;
        }
        if(((1 << j) & (mask)) == 0) // j is out
        {
            rec(mask, i, j-1, n, round, fp, sp);
            return;
        }
        if(i != fp && i != sp) // i can be out
        {
            rec(((mask) ^ (1 << i)), i+1, j-1, n, round, fp, sp);
        }
        if(j != fp && j != sp) // j can be out
        {
            rec(((mask) ^ (1 << j)), i+1, j-1, n, round, fp, sp);
        }
    }
    
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) 
    {
        rec((1 << n)-1, 0, n-1, n, 1, firstPlayer-1, secondPlayer-1);
        return {min_ans, max_ans};
    }
};
