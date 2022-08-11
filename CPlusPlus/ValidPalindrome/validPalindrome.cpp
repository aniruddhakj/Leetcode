// Author : Aniruddha Krishna Jha
// Date : 11/08/2022

/*******************************************************************************
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, 
it reads the same forward and backward. 
Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
*******************************************************************************/

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while(l < r){
            if(!isalnum(s[l]))
                ++l;
            else if(!isalnum(s[r]))
                --r;
            else{ //if falls to else case, operate on l and r for next itr
                if(tolower(s[l++]) != tolower(s[r--]))
                    return false;
            }
        }
        return true;
    }
};
