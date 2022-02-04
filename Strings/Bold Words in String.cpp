// By Vishwam Shriram Mundada
// https://www.lintcode.com/problem/812/description
// Easy, Brute Force

/*
Given a set of keywords words and a string S, make all appearances of all keywords in S bold. Any letters between <b> and </b> tags become bold.
The returned string should use the least number of tags possible, and of course the tags should form a valid combination.

Wechat reply the 【812】 get the latest frequent Interview questions . (wechat id : jiuzhang15)

    words has length in range [0, 50].
    words[i] has length in range [1, 10].
    S has length in range [0, 500].
    All characters in words[i] and S are lowercase letters.

Example

Example 1:

Input:

["ab", "bc"]
"aabcd"

Output:

"a<b>abc</b>d"

Explanation:
Note that returning "a<b>a<b>b</b>c</b>d" would use more tags, so it is incorrect.

Example 2:
Input:

["bcccaeb","b","eedcbda","aeebebebd","ccd","eabbbdcde","deaaea","aea","accebbb","d"]
"ceaaabbbedabbecbcced"

Output:
"ceaaa<b>bbb</b>e<b>d</b>a<b>bb</b>ec<b>b</b>cce<b>d</b>"
*/

class Solution {
public:
    string boldWords(vector<string> &words, string &s)
    {
        vector<int> ind(505, 0);
        for(auto& w : words)
            for(int i = 0; i <= s.size()-w.size(); ++i)
                if(s.substr(i, w.size()) == w)
                    for(int j = i; j < i+w.size(); ++j)
                        ind[j]++;

        string ans;
        int i = 0;
        while(i < s.size())
        {
            if(ind[i] > 0)
            {
                int j = i;
                ans += "<b>";
                while(j < s.size() && ind[j] > 0)
                {
                    ans.push_back(s[j]);
                    ++j;
                }
                ans += "</b>";
                i = j;
            }
            else
            {
                ans.push_back(s[i]);
                i++;
            }
        }
        return ans;
    }
};
