// Author   : Aniruddha Krishna Jha
// Date     : 19/04/2022
// Link     : https://leetcode.com/problems/valid-anagram/

/*******************************************************************************
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true

Example 2:

Input: s = "rat", t = "car"
Output: false
*******************************************************************************/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        
        vector<int>cnt(26, 0); //map to store cnt of each char
        
        for(char ch : s){
            cnt[ch - 'a']++; //increment cnt of ch foreach appearance in s
        }
        for(char ch : t){
            cnt[ch - 'a']--; //decrement cnt for each appearance in t
            if(cnt[ch - 'a'] < 0) // if cnt ch in s ≠ ch in t
                return false;
        }
        return true;
    }
};
