# Author    : Aniruddha Krishna Jha
# Date      : 25/05/2025
# Link      : https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/

'''*******************************************************************************
You are given an array of strings words. Each element of words consists of two lowercase English letters.

Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.

Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.

A palindrome is a string that reads the same forward and backward.

 

Example 1:

Input: words = ["lc","cl","gg"]
Output: 6
Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
Note that "clgglc" is another longest palindrome that can be created.
Example 2:

Input: words = ["ab","ty","yt","lc","cl","ab"]
Output: 8
Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
Note that "lcyttycl" is another longest palindrome that can be created.

*******************************************************************************'''

# import collections
# from typing import List

class Solution:
    '''
    Hashmap -> Count the frequency of each word, then check for pairs of words that can form a palindrome.
    Time Complexity: O(n * m) where n is the number of words and m is the length of each word (which is 2 in this case).
    Space Complexity: O(n)
    '''
    def longestPalindrome(self, words: List[str]) -> int:
        cnt = collections.Counter(words)
        length = 0
        odd_flag = 0

        for w, freq in cnt.items():
            # reverse the word to check word type (same char or diff char)
            r = w[::-1]
            if w == r:
                # if same char then add 4 to length per pair
                length += (freq // 2) * 4
                if freq % 2:
                    odd_flag = 1
            # check for < or > to add the length only once per pair
            elif w > r and r in cnt:
                length += min(freq, cnt[r]) * 4

        return length + (odd_flag * 2)