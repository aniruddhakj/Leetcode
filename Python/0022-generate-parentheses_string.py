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
    String with Backtracking -> backtrack when opening < n 
    or closing < opening else append to result
    '''
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        
        def backtrack(opening, closing, path):
            if opening < n:
                backtrack(opening + 1, closing, path + "(")

            if closing < opening:
                backtrack(opening, closing + 1, path + ")")

            if opening == closing == n:
                res.append(path)
                return

        backtrack(0, 0, "")
        return res