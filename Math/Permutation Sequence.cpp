// By Vishwam Shriram Mundada
// https://leetcode.com/problems/permutation-sequence/
// Good

class Solution {
public:
    string getPermutation(int n, int k) 
    {
        set<char> st;
        for(int i = 1; i <= n; ++i)
            st.insert('0' + i);
        
        string s;
        vector<int> fact({1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880});
        while(n--)
        {
            int head = k / fact[n];
            int mod = k % fact[n];
            k -= (head - (mod == 0 ? 1 : 0)) * fact[n];
            
            auto it = st.begin();
            if(mod == 0)
                head--;
            
            while(head > 0 && head--)
                it++;
            
            s.push_back(*it);
            st.erase(it);
        }
        return s;
    }
};


// recursion

class Solution {
public:
    set<char> st;
    vector<int> fact;
    
    string rec(int n, int k)
    {
        if(n == 1)
            return string({*(st.begin())});
        
        int head = k / fact[n-1];
        int mod = k % fact[n-1];
        k -= (head - (mod == 0 ? 1 : 0)) * fact[n-1];
        
        auto it = st.begin();
        if(mod == 0)
            head--;
        while(head > 0 && head--)
            it++;
        
        string s({*it});
        st.erase(it);
        return s + rec(n-1, k);
    }
    
    string getPermutation(int n, int k) 
    {
        for(char ch = '1'; ch <= '0'+n; ++ch)
            st.insert(ch);
        fact = vector<int>({1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880});
        return rec(n, k);
    }
};
