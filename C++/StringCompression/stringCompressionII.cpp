// Author : Aniruddha Krishna Jha
// Date : 15/10/2022

/*******************************************************************************
Run-length encoding is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). 
For example, to compress the string "aabccc" we replace "aa" by "a2" and replace "ccc" by "c3". 
Thus the compressed string becomes "a2bc3".

Notice that in this problem, we are not adding '1' after single characters.

Given a string s and an integer k. 
You need to delete at most k characters from s such that the run-length encoded version of s has minimum length.

Find the minimum length of the run-length encoded version of s after deleting at most k characters.

 

Example 1:

Input: s = "aaabcccd", k = 2
Output: 4
Explanation: Compressing s without deleting anything will give us "a3bc3d" of length 6. 
Deleting any of the characters 'a' or 'c' would at most decrease the length of the compressed string to 5, 
for instance delete 2 'a' then we will have s = "abcccd" which compressed is abc3d. 
Therefore, the optimal way is to delete 'b' and 'd', then the compressed version of s will be "a3c3" of length 4.
*******************************************************************************/

class Solution {
public:
    
    int getLengthOfOptimalCompression(string s, int k) {
        //dp[i][c] is current idx and characters to delete
        
        auto len = [&](int c) {return (c == 1 ? 1 : c < 10 ? 2 : c < 100 ? 3: 4); };
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, n));
        dp[0][0] = 0;
        
        for(int i = 1; i < n + 1; ++i){
            for(int j = 0; j < k + 1; ++j){
                
                int del = 0, cnt = 0, p;
                
                for(p = i; p > 0; --p){ //keep s[i] remove all the different 
                    if (s[p - 1] == s[i - 1]) cnt++;
                    else del++;
                    if(j < del ) break;
                    dp[i][j] = min(dp[i][j], dp[p - 1][j - del] + len(cnt));
                }
                
                if (j > 0) //delete s[i]
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            }
        }
    
        return dp[n][k];
    }
};
