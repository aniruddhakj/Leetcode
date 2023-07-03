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
    Two pointer approach - one from the start and one from the end
    if char at start and end are not alphanumeric, move the pointers
    if char at start and end are alphanumeric, check if they are equal
    if not equal, return False

    Time Complexity: O(n)
    Space Complexity: O(1)
    '''
    def isPalindrome(self, s: str) -> bool:
        l, r = 0, len(s)-1
        while l < r:
            if not s[l].isalnum(): l += 1
            elif not s[r].isalnum(): r -= 1
            elif s[l].lower() != s[r].lower(): return False # main logic
            else:
                l += 1
                r -= 1
        return True
    