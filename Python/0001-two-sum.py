# Author    : Aniruddha Krishna Jha   
# Date      : 29/09/2024
# Link      : https://leetcode.com/problems/two-sum/

'''********************************************************************************** 
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example :

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
**********************************************************************************'''

class Solution:
    '''
    One pass Hash Map -> Store the previous values in a map and check if the difference is present in the map
    
    Time Complexity: O(n)
    Space Complexity: O(n)
    '''
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        prevValMap = {} # val -> idx
        for i, curr in enumerate(nums):
            diff = target - curr
            if diff in prevValMap:
                return [prevValMap[diff], i]
            prevValMap[curr] = i
        return []
