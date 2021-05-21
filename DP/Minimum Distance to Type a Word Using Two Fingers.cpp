// By Vishwam Shriram Mundada
// https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/
// Decent

/*
You have a keyboard layout as shown above in the XY plane, where each English uppercase letter is located at some coordinate, 
for example, the letter A is located at coordinate (0,0), the letter B is located at coordinate (0,1), 
the letter P is located at coordinate (2,3) and the letter Z is located at coordinate (4,1).

Given the string word, return the minimum total distance to type such string using only two fingers. 
The distance between coordinates (x1,y1) and (x2,y2) is |x1 - x2| + |y1 - y2|. 

Note that the initial positions of your two fingers are considered free so don't count towards your total distance, 
also your two fingers do not have to start at the first letter or the first two letters.

Example 1:
Input: word = "CAKE"
Output: 3
Explanation: 
Using two fingers, one optimal way to type "CAKE" is: 
Finger 1 on letter 'C' -> cost = 0 
Finger 1 on letter 'A' -> cost = Distance from letter 'C' to letter 'A' = 2 
Finger 2 on letter 'K' -> cost = 0 
Finger 2 on letter 'E' -> cost = Distance from letter 'K' to letter 'E' = 1 
Total distance = 3

Example 2:
Input: word = "HAPPY"
Output: 6
Explanation: 
Using two fingers, one optimal way to type "HAPPY" is:
Finger 1 on letter 'H' -> cost = 0
Finger 1 on letter 'A' -> cost = Distance from letter 'H' to letter 'A' = 2
Finger 2 on letter 'P' -> cost = 0
Finger 2 on letter 'P' -> cost = Distance from letter 'P' to letter 'P' = 0
Finger 1 on letter 'Y' -> cost = Distance from letter 'A' to letter 'Y' = 4
Total distance = 6

Example 3:
Input: word = "NEW"
Output: 3

Example 4:
Input: word = "YEAR"
Output: 7

Constraints:
    2 <= word.length <= 300
    Each word[i] is an English uppercase letter.

*/

class Solution {
public:
    int dp[301][27][27]; // we are taking 27 because state 26 is reserved for initial sitiuation where finger is pointing nowhere
    
    int give_dist(char ch1, char ch2)
    {
        if(ch1 == 'Z'+1) // because finger is pointing nowhere we can directly get it to desired character with dist = 0
            return 0;
        
        int a = ch1 - 'A';
        int b = ch2 - 'A';
        
        int x1 = a/6;
        int y1 = (a - 6*x1);
        
        int x2 = b/6;
        int y2 = (b - 6*x2);
        
        return abs(x1-x2) + abs(y1-y2);
    }
    
    int rec(int index, string w, char f1, char f2)
    {
        if(index == w.size())
            return 0;
        
        if(dp[index][f1-'A'][f2-'A'] != -1)
            return dp[index][f1-'A'][f2-'A'];
        
        // ans1 = get finger1 at word[index]
        // ans2 = get finger2 at word[index]
        // ans = min(ans1, ans2)
        return dp[index][f1-'A'][f2-'A'] = min(give_dist(f1, w[index]) + rec(index+1, w, w[index], f2), 
                                        give_dist(f2, w[index]) + rec(index+1, w, f1, w[index]));
    }
    
    int minimumDistance(string word) 
    {
        int ans = INT_MAX;
        memset(dp, -1, sizeof(dp));
        // we could've used two loops as wrtten in comments (as I had also done before doesnt (give success)) but its waste, 
        // at first attempt we can directly get any finger to desired character
        // for(char c1 = 'A'; c1 <= 'Z'; ++c1)
        //     for(char c2 = 'A'; c2 <= 'Z'; ++c2)
        //         ans = min(ans, rec(0, word, c1, c2));
        
        // 'Z'+1 is nowhere and dist('Z'+1 , 'any_char') = 0
        return rec(0, word, 'Z'+1, 'Z'+1);
    }
};
