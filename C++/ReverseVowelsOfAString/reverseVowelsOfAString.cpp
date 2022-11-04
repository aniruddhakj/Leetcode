// Author : Aniruddha Krishna Jha
// Date : 04/11/2022

/*******************************************************************************
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

Example 1:

Input: s = "hello"
Output: "holle"

Example 2:

Input: s = "leetcode"
Output: "leotcede"
*******************************************************************************/

class Solution {
public:
    string reverseVowels(string s) {
        // set to store all the vowels
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int l = 0, r = s.size() - 1;
        while(l < r) {
            while(l < r && !st.count(s[l])) ++l;
            
            while(l < r && !st.count(s[r])) --r;
            
            // move the pointers after the swap
            swap(s[l++], s[r--]);
        }
        return s;
    }
};
