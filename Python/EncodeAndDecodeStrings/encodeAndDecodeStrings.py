# Author : Aniruddha Krishna Jha   
# Date   : 01/07/2023

'''********************************************************************************** 
Design an algorithm to encode a list of strings to a string. 
The encoded string is then sent over the network and is decoded back to the original list of strings.

Please implement encode and decode

Example 1:

Input: ["lint","code","love","you"]
Output: ["lint","code","love","you"]

Explanation: 
One possible encode method is: "lint:;code:;love:;you"

Example 2:

Input: ["we", "say", ":", "yes"]
Output: ["we", "say", ":", "yes"]

Explanation:
One possible encode method is: "we:;say:;:::;yes"
**********************************************************************************'''

class Solution:
    """
    @param: strs: a list of strings
    @return: encodes a list of strings to a single string.
    """
    def encode(self, strs):
        # encoding formula used is len(string) + ":" + string
        res = ""
        for s in strs:
            res += str(len(s)) + ":" + s
        return res

    """
    @param: str: A string
    @return: decodes a single string to a list of strings
    """
    def decode(self, str):
        res, i = [], 0
        while i < len(str):
            j = str.find(":", i)
            i = j + 1 + int(str[i:j])
            res.append(str[j+1:i])
        return res