// Author : Aniruddha Krishna Jha
// Date : 19/04/2022

/*******************************************************************************
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

Example 1:

Input: s = "leetcode"
Output: 0

Example 2:

Input: s = "loveleetcode"
Output: 2
*******************************************************************************/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> freqMap;
        int ans = INT_MAX;
        //hashmap for freq of char in s
        for(int i = 0; i < s.size(); i++){
            if(freqMap.find(s[i]) == freqMap.end())
                freqMap[s[i]] = i;
            else
                freqMap[s[i]] = INT_MAX;
        }
        for(auto it : freqMap)
            ans = min(it.second, ans);
        return (ans == INT_MAX)? -1 : ans;
    }
};
