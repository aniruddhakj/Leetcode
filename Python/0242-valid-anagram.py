# Author    : Aniruddha Krishna Jha   
# Date      : 30/06/2023
# Link      : https://leetcode.com/problems/valid-anagram/

'''********************************************************************************** 
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true

Example 2:

Input: s = "rat", t = "car"
Output: false
**********************************************************************************'''

class Solution:
    '''
    Create a map each for count of char in s and t
    compare the counts
    '''
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        cntS, cntT = {}, {}

        for i in range(len(s)):
            cntS[s[i]] = 1 + cntS.get(s[i], 0)
            cntT[t[i]] = 1 + cntT.get(t[i], 0) 
        
        return cntS == cntT
