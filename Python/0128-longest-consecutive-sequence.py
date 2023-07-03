# Author    : Aniruddha Krishna Jha   
# Date      : 01/07/2023
# Link      : https://leetcode.com/problems/longest-consecutive-sequence/

'''********************************************************************************** 
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
**********************************************************************************'''

class Solution:
    '''
    set approach: if num - 1 is not present in set, then it is the start of the seq
    Loop to find current length of seq, and update longest

    Time Complexity: O(n)
    Space Complexity: O(n)
    '''
    def longestConsecutive(self, nums: List[int]) -> int:
        numSet, longest = set(nums), 0
        for num in nums:
            # if this is the start of the seq
            # i.e., (num - 1) is not present
            if (num - 1) not in numSet:
                length = 1
                # loop to see length of seq
                while (num + length) in numSet:
                    length += 1
                longest = max(longest, length)
        
        return longest