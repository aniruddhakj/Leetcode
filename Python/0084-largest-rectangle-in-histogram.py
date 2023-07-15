# Author   : Aniruddha Krishna Jha
# Date     : 10/07/2023
# Link     : https://leetcode.com/problems/largest-rectangle-in-histogram/

'''*******************************************************************************
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
return the area of the largest rectangle in the histogram.

Example :

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
*******************************************************************************'''

class Solution:
    '''
    Stack based solution -> store the index and height of the bar in the stack
    if current height < height of the bar at stack top, pop the stack and calculate the area
    maxArea = max(maxArea, height * (i - idx))

    Time Complexity: O(n)
    Space Complexity: O(n)
    '''
    def largestRectangleArea(self, heights: List[int]) -> int:
        maxArea = 0
        stack = [] # pair of (index, height)

        for i, h in enumerate(heights):
            start = i
            while stack and stack[-1][1] > h:
                idx, height = stack.pop()
                maxArea = max(maxArea, height * (i - idx))
                start = idx
            stack.append((start, h))

        for i, h in stack:
            maxArea = max(maxArea, h * (len(heights) - i))

        return maxArea