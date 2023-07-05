# Author   : Aniruddha Krishna Jha
# Date     : 03/07/2023
# Link     : https://leetcode.com/problems/permutation-in-string/

'''*******************************************************************************
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
*******************************************************************************'''

class Solution:
    '''
    Sliding Window 

    Time Complexity: O(n)
    Space Complexity: O(1)
    '''
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2): return False

        s1Count, s2Count = [0] * 26, [0] * 26
        # populate frequency maps
        for i in range(len(s1)):
            s1Count[ord(s1[i]) - ord("a")] += 1
            s2Count[ord(s2[i]) - ord("a")] += 1

        matches = 0
        for i in range(26):
            matches += (1 if s1Count[i] == s2Count[i] else 0)

        l = 0
        for r in range(len(s1), len(s2)):
            if matches == 26: return True

            idx = ord(s2[r]) - ord("a")
            s2Count[idx] += 1
            if s1Count[idx] == s2Count[idx]:
                matches += 1
            elif s1Count[idx] + 1 == s2Count[idx]:
                matches -= 1

            idx = ord(s2[l]) - ord("a")
            s2Count[idx] -= 1
            if s1Count[idx] == s2Count[idx]:
                matches += 1
            elif s1Count[idx] - 1 == s2Count[idx]:
                matches -= 1
            l += 1
        return matches == 26