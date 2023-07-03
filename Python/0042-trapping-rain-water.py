# Author    : Aniruddha Krishna Jha   
# Date      : 02/07/2023
# Link      : https://leetcode.com/problems/trapping-rain-water/

'''********************************************************************************** 
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining. 

Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped.

Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
**********************************************************************************'''

class Solution:
    '''
    Two Pointer Approach -> max height on both sides of the pointer
    
    Time Complexity: O(n)
    Space Complexity: O(1)
    '''
    def trap(self, height: List[int]) -> int:
        if not height: return 0

        l, r = 0, len(height) -1
        lmax, rmax = height[l], height[r]
        res = 0
        while l < r:
            if lmax < rmax:
                l += 1
                lmax = max(lmax, height[l])
                res += lmax - height[l]
            else:
                r -= 1
                rmax = max(rmax, height[r])
                res += rmax - height[r]
        return res