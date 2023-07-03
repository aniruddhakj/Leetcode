// Author   : Aniruddha Krishna Jha
// Date     : 13/08/2022
// Link     : https://leetcode.com/problems/longest-substring-without-repeating-characters/

/*******************************************************************************
Given a string s, find the length of the longest substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
*******************************************************************************/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //create a set of char, window init
        unordered_set<char>st;
        int l = 0, r = 0, mlen = 0;
        
        while(r < s.size()){
            //if char not found, insert in set extend the window to right 
            if(st.count(s[r]) == false){
                st.insert(s[r++]);
                mlen = max(mlen, r - l);
            }
            else{
                st.erase(s[l++]);               
            }

            //else, remove from set shorten the window from left
        }
        return mlen;
    }
};
