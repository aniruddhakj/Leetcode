# Author   : Aniruddha Krishna Jha
# Date     : 05/07/2023
# Link     : https://leetcode.com/problems/valid-parentheses/

'''*******************************************************************************
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
 
Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "()[]{}"
Output: true
*******************************************************************************'''

class Solution:
    '''
    Stack with Map -> map closing brackets to opening brackets

    Time Complexity: O(n)
    Space Complexity: O(n)
    '''
    def isValid(self, s: str) -> bool:
        stack =[]
        closeToOpen = {')':'(', '}':'{', ']':'['}

        for c in s:
            if c in closeToOpen:
                # if stack empty or top of stack is not the corresponding opening bracket -> Invalid
                if not stack or stack.pop() != closeToOpen[c]:
                    return False
            else:
                stack.append(c)
        return not stack # stack is empty