# Author: Aniruddha Krishna Jha
# Date: 30/06/2023

'''********************************************************************************** 
Given an integer array nums, return true if any value appears at least twice in the array, 
and return false if every element is distinct.

Example 1:

Input: nums = [1,2,3,1]
Output: true

Example 2:

Input: nums = [1,2,3,4]
Output: false
**********************************************************************************'''


class Solution:
    '''
    Put all the values while iterating in a set
    If num[i] is already in set, duplicate found
    '''
    def containsDuplicate(self, nums: List[int]) -> bool:
        hashSet = set()
        for i in nums:
            if i in hashSet:
                return True
            hashSet.add(i)
        return False
