# Author    : Aniruddha Krishna Jha   
# Date      : 01/07/2023
# Link      : https://leetcode.com/problems/valid-palindrome/

'''********************************************************************************** 
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. 
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
**********************************************************************************'''

class Solution:
    '''
    Single pass approach
    check if the character is alphanumeric, if yes, add it to the new string
    check if the new string is equal to the reverse of the new string

    Time Complexity: O(n)
    Space Complexity: O(n)
    '''
    def isPalindrome(self, s: str) -> bool:
        newStr = ""
        for c in s:
            if c.isalnum():
                newStr += c.lower()
        return newStr == newStr[::-1]