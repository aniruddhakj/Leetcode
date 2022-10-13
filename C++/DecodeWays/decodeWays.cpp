// Author : Aniruddha Krishna Jha
// Date : 18/08/2021

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
class Solution {
public:
    int check(char ch){
        //check if char is 0
        return (!isdigit(ch) || ch=='0') ? 0 : 1;
    }

    int check(char ch1, char ch2){
        // to check it's between 10 and 26
        return (ch1=='1' || (ch1=='2' && ch2<='6')) ? 1: 0;
    }    
    int numDecodings(string s) {
        if (s.size() <= 0) return 0;
        if (s.size() == 1) return check(s[0]);

        int* dp = new int[s.size()];
        memset(dp, 0, s.size() * sizeof(int));

        dp[0] = check(s[0]);
        dp[1] = check(s[0]) *  check(s[1]) + check(s[0], s[1]) ;
        for (int i=2; i<s.size(); i++) {
            if (!isdigit(s[i])) break; 

            if (check(s[i]))
                dp[i] = dp[i-1];

            if (check(s[i-1], s[i]))
                dp[i] += dp[i-2];
        }
        int result = dp[s.size()-1];
        delete[] dp;
        return result;
    }
};