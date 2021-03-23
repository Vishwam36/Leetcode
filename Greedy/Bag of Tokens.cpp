// By Vishwam Shriram Mundada
// https://leetcode.com/problems/bag-of-tokens/
// Easy

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int p) 
    {
        sort(tokens.begin(), tokens.end());
        
        int i = 0, j = tokens.size()-1;
        int score = 0, maxScore = 0;
        
        while(i <= j)
        {
            if(p >= tokens[i])
            {
                p -= tokens[i];
                score++;
                ++i;
            }
            else if(score > 0)
            {
                p += tokens[j];
                --j;
                score--;
            }
            else
            {
                break;
            }
            maxScore = max(maxScore, score);
        }
        return maxScore;
    }
};
