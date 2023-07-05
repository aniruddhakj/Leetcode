# Author   : Aniruddha Krishna Jha
# Date     : 04/07/2023
# Link     : https://leetcode.com/problems/minimum-window-substring/


'''*******************************************************************************
Given two strings s and t of lengths m and n respectively, 
return the minimum window substring of s such that every character in t (including duplicates) is included in the window. 
If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
*******************************************************************************'''

class Solution:
    '''
    Sliding window approach -> maintain a sliding window with all the characters of t
    and then shrink the window from left to find the minimum window

    Time Complexity: O(|S| + |T|)
    Space Complexity: O(|S| + |T|) for the hashmap and the window
    '''
    def minWindow(self, s: str, t: str) -> str:
        if not t: return ""
        
        countT, window = {}, {}
        for c in t:
            countT[c] = 1 + countT.get(c, 0)
        
        # how many char we have vs how many needed
        have, need = 0, len(countT)
        res, resLen = [-1, -1], float("infinity")
        l = 0
        for r in range(len(s)):
            c = s[r]
            window[c] = 1 + window.get(c, 0)
            if c in countT and countT[c] == window[c]:
                have += 1

            while have == need: #condition is met
                if (r - l + 1) < resLen:
                    res = [l, r]
                    resLen = r - l + 1
                
                # pop from left and update to find min window
                window[s[l]] -= 1
                if s[l] in countT and countT[s[l]] > window[s[l]]:
                    have -= 1
                l += 1
        l, r = res
        return s[l:r + 1] if resLen != float("infinity") else ""