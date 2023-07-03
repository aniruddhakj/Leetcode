# Author    : Aniruddha Krishna Jha   
# Date      : 02/07/2023
# Link      : https://leetcode.com/problems/container-with-most-water/

'''********************************************************************************** 
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.

Example:

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. 
In this case, the max area of water (blue section) the container can contain is 49.
**********************************************************************************'''

class Solution:
    '''
    Two Pointer Approach -> fix the left and right pointer and move the one with smaller height
    
    Time Complexity: O(n)
    Space Complexity: O(1)
    '''
    def maxArea(self, height: List[int]) -> int:
        l, r = 0, len(height) - 1
        maxH = max(height)
        res = 0
        while l < r:
            res = max(res, (r-l) * min(height[r], height[l]))
            if height[l] < height[r]:
                l += 1
            else: r -= 1

            if (r - l) * maxH <= res: break
        
        return res