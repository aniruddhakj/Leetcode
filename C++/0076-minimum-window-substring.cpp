// Author   : Aniruddha Krishna Jha
// Date     : 22/10/2022
// Link     : https://leetcode.com/problems/minimum-window-substring/

/*******************************************************************************
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
*******************************************************************************/

// INTUITION: We need to find a substring of it which satisfy some restrictions
// A general way is to use a hashmap assisted with two pointers.

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map (128, 0);
        for(auto c: t) map[c]++; // init the map
        
        int cnt = t.size(); // counter for the substring length
        int l = 0, r = 0; // 2 ptrs for traversing
        
        int res = INT_MAX, head = 0;
        while(r < s.size()){
            if(map[s[r++]]-- > 0) cnt--;
            while(cnt == 0) { //valid
                if(r - l < res) {
                    head = l;
                    res = r - head;  
                } 
                if(map[s[l++]]++ == 0) cnt++;  //make it invalid
            }  
        }
        
        return res == INT_MAX? "" : s.substr(head, res);
    }
};
