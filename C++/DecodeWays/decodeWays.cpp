// Author : Aniruddha Krishna Jha
// Date : 20/10/2022

/*******************************************************************************
A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"

To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The answer is guaranteed to fit in a 32-bit integer.

Example :

Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
*******************************************************************************/

// INTUITION:     DP: At each digit, check validity of ones & tens, 
// if valid add to number of ways
// Recurrence : dp[i] += dp[i-1] (if valid) + dp[i-2] (if valid)

class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1; dp[1] = 1;
        
        for(int i = 2; i < n + 1; ++i){
            int units = stoi(s.substr(i - 1, 1));
            if(units >= 1 && units <= 9 ) dp[i] += dp[i - 1];
            
            int tens = stoi(s.substr(i - 2, 2));
            if(tens >= 10 && tens <= 26) dp[i] += dp[i - 2];
            
        }
        
        return dp[n];
    }
};
