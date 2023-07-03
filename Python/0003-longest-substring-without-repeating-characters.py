# Author    : Aniruddha Krishna Jha   
# Date      : 02/07/2023
# Link      : https://leetcode.com/problems/longest-substring-without-repeating-characters/

'''********************************************************************************** 
Given a string s, find the length of the longest  substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
**********************************************************************************'''

class Solution:
    '''
    Sliding Window -> keep members in Hashset 
    Update max length after new addition

    Time Complexity: O(n)
    Space Complexity: O(n)
    '''
    def lengthOfLongestSubstring(self, s: str) -> int:
        l, res = 0, 0
        hashSet = set()

        for r in range(len(s)):
            # if already in set, create new window from this pt as new end
            while s[r] in hashSet:
                hashSet.remove(s[l])
                l += 1
            hashSet.add(s[r])
            res = max(res, r - l + 1)
        return res