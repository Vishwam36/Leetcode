// https://leetcode.com/problems/airplane-seat-assignment-probability/description/
// Good
// Ref : https://www.youtube.com/watch?v=NyL0ws-65aQ

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        return (n == 1 ? 1.0 : 0.5);
    }
};
