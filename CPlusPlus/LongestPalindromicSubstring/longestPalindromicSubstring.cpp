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
        int n = s.size();
        if(n == 0) return ""; // empty string case
        int maxLen = 1;
        string maxStr = s.substr(0, 1);
        for(int i = 0; i < n; i++){
            string str = palindromeHelper(s, i, i);
            if(str.size() > maxLen){
                maxLen = str.size();
                maxStr = str;
            }
            //extra check for complete string
            str = palindromeHelper(s, i, i + 1);
            if(str.size() > maxLen){
                maxLen = str.size();
                maxStr = str;
            }
        }
        return maxStr;
    }
    string palindromeHelper(string s, int left, int right){
        //two pointer method to check for greatest palindrome substring
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }
};
