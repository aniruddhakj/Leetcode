// Author : Aniruddha Krishna Jha
// Date : 20/10/2022

/*******************************************************************************
Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

 
Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
*******************************************************************************/


// INTUITION: same as Longest Palindromic Substrings leetcode 5

class Solution {
public:
    int countSubstrings(string s) {
        // different cases for odd/even length palindrome
        int cnt = 0,  n = s.size();
        
        for(int i = 0; i < n; ++i) {
            // case odd length palindrome
            int l = i, r = i;
            // check for palindrome
            while(l >= 0 && r < n && s[l] == s[r]) {
                // if palindrome increment count
                cnt++;
                l--; r++;
            }
            
            // case even length palindrome, init r with i + 1
            l = i; r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r]) {
                cnt++;
                l--; r++;
            }
        }
            
        return cnt;
    }
};
