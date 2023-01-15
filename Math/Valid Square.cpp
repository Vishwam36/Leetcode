// https://leetcode.com/problems/valid-square/description/
// Easy

class Solution {
public:
    double length(vector<int> &p1, vector<int> &p2)
    {
        return sqrt((p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]));
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        map<double, int> mp;
        mp[length(p1, p2)]++;
        mp[length(p2, p3)]++;
        mp[length(p3, p4)]++;
        mp[length(p4, p1)]++;
        mp[length(p1, p3)]++;
        mp[length(p2, p4)]++;

        auto it = mp.begin();
        if(it->second != 4)
        {
            return false;
        }
        it++;
        return it->second == 2;
    }
};
