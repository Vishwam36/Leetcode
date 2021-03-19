// By Vishwam Shriram Mundada
// https://leetcode.com/problems/binary-watch/
// Decent variety

vector<int> hours({1, 2, 4, 8});
vector<int> mins({1, 2, 4, 8, 16, 32});

string convert(pair<int, int> p)
{   
    string ans = "";
    
    ans += to_string(p.first);
    
    ans += ":";
    
    if(p.second >= 10)
        ans += to_string(p.second);
    else
        ans += "0" + to_string(p.second);
    
    return ans;
}

void rec(set<pair<int, int> > &ans, pair<int, int> p, int i1, int i2, int n)
{
    if(n == 0)
    {
        ans.insert(p);
        return;
    }
    for(int i = i1; i < hours.size(); ++i)
    {
        p.first += hours[i];
        rec(ans, p, i+1, i2, n-1);
        p.first -= hours[i];
    }
    for(int i = i2; i < mins.size(); ++i)
    {
        p.second += mins[i];
        rec(ans, p, i1, i+1, n-1);
        p.second -= mins[i];
    }
}

class Solution {
public:
    vector<string> readBinaryWatch(int num) 
    {
        set<pair<int, int> > ans;
        pair<int, int> p = {0, 0};
        rec(ans, p, 0, 0, num);
        
        vector<string> v;
        auto it = ans.begin();
        for(it = ans.begin(); it != ans.end(); ++it)
            if(it -> first < 12 && it -> second < 60)
                v.push_back(convert(*it));
        
        return v;
    }
};
