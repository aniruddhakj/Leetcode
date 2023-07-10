# Author   : Aniruddha Krishna Jha
# Date     : 06/07/2023
# Link     : https://leetcode.com/problems/generate-parentheses/

'''*******************************************************************************
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
*******************************************************************************'''

class Solution:
    '''
    Stack with Backtracking -> backtrack when opening < n or closing < opening else append to result
    '''
    def generateParenthesis(self, n: int) -> List[str]:
        stack = []
        res = []
        
        def backtrack(opening, closing):
            if opening < n:
                stack.append('(')
                backtrack(opening + 1, closing)
                stack.pop()

            if closing < opening:
                stack.append(')')
                backtrack(opening, closing + 1)
                stack.pop()

            if opening == closing == n:
                res.append("".join(stack))
                return

        backtrack(0, 0)
        return res