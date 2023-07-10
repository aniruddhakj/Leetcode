# Author   : Aniruddha Krishna Jha
# Date     : 06/07/2023
# Link     : https://leetcode.com/problems/daily-temperatures/

'''*******************************************************************************
Given an array of integers temperatures represents the daily temperatures, 
return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. 
If there is no future day for which this is possible, keep answer[i] == 0 instead.

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
*******************************************************************************'''

class Solution:
    '''
    Stack -> store (temp, index) in stack and pop when current temp > stack temp

    Time Complexity  : O(n)
    Space Complexity : O(n)
    '''

    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        res = [0] * len(temperatures)
        stack = [] # (temp, index)

        for idx, temp in enumerate(temperatures):
            while stack and temp > stack[-1][0]:
                stackTemp, stackIdx = stack.pop()
                res[stackIdx] = idx - stackIdx

            stack.append([temp, idx])
        return res