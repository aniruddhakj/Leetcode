// Author : Aniruddha Krishna Jha
// Date : 16/06/2022

/*******************************************************************************
Given a string s, return the longest palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:

Input: s = "cbbd"
Output: "bb"
*******************************************************************************/

class Solution {
public:
    string longestPalindrome(string s) {
        // different cases for odd/even length palindrome
        int resLen = 0,  n = s.size();
        
        string res = "";
        
        for(int i = 0; i < n; ++i) {
            // case odd length palindrome
            int l = i, r = i;
            // check for palindrome
            while(l >= 0 && r < n && s[l] == s[r]) {
                // if current len is greater than stored result len
                // update length of res and res itself
                if( r - l + 1 > resLen) { 
                    resLen = r - l + 1;  
                    res = s.substr(l, resLen); 
                }
                l--; r++;
            }
            
            // case even length palindrome, init r with i + 1
            l = i; r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r]) {
                if( r - l + 1 > resLen) {
                    resLen = r - l + 1; 
                    res = s.substr(l, resLen);
                }
                l--; r++;
            }
            
        }
            
        return res;
    }
};
