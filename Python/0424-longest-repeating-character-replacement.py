# Author   : Aniruddha Krishna Jha
# Date     : 03/07/2023
# Link     : https://leetcode.com/problems/longest-repeating-character-replacement/

'''********************************************************************************** 
You are given a string s and an integer k. 
You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achive this answer too.
**********************************************************************************'''

class Solution:
    '''
    Sliding Window -> maxFreq in the window + k should be less than window size

    Time Complexity: O(n)
    Space Complexity: O(1) -> the map will have at most 26 entries
    '''
    def characterReplacement(self, s: str, k: int) -> int:
        count = {}
        l, res = 0, 0
        maxFreq = 0
        for r in range(len(s)):
            count[s[r]] = 1 + count.get(s[r], 0)
            maxFreq = max(maxFreq, count[s[r]]) #max freq in the map
            # while replacement is still possible
            while (r - l + 1) - maxFreq > k:
                count[s[l]] -=1
                l += 1

            res = max(res, r - l + 1)
        return res