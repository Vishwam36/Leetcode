// https://leetcode.com/problems/max-points-on-a-line/description/
// Maps, Maths

class Solution {
public:
    double inf = 100000.0;
    int maxPoints(vector<vector<int>>& points) {
        map<pair<double, double>, set<pair<double, double> > > mp;
        for(int i = 0; i < points.size(); ++i)
        {
            for(int j = i+1; j < points.size(); ++j)
            {
                double x1 = points[i][0], y1 = points[i][1];
                double x2 = points[j][0], y2 = points[j][1];

                double m = (x1 != x2 ? (y1-y2)/(x1-x2) : inf);
                double c = y1 - (m*x1);

                mp[{m, c}].insert({x1, y1});
                mp[{m, c}].insert({x2, y2});
            }
        }
        int ans = 0;
        for(auto it : mp)
        {
            ans = max(ans, (int)(it.second.size()));
        }
        return (ans > 0 ? ans : 1);
    }
};
