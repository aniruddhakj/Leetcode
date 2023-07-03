# Author    : Aniruddha Krishna Jha   
# Date      : 30/06/2023
# Link      : https://leetcode.com/problems/group-anagrams/

'''********************************************************************************** 
Given an array of strings strs, group the anagrams together. 
You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:

Input: strs = [""]
Output: [[""]]
**********************************************************************************'''


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = collections.defaultdict(list)

        for s in strs:
            cnt = [0] * 26 # a...z
            # for each char in s, count freq 
            for ch in s:
                cnt[ord(ch) - ord('a')] += 1
            # create key value based on count
            res[tuple(cnt)].append(s)
        
        return res.values()