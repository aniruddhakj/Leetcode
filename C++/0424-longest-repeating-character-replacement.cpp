// Author   : Aniruddha Krishna Jha
// Date     : 17/10/2022
// Link     : https://leetcode.com/problems/longest-repeating-character-replacement/

/*******************************************************************************
You are given a string s and an integer k.
You can choose any character of the string and change it to any other uppercase English character. 
You can perform this operation at most k times.

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
*******************************************************************************/

// INTUITION: window = end - start + 1, mc is max appearing char in a window
// if there are more char in a window then replacements possible
// move the window (start++), else update the length

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26, 0);
        int start = 0, end = 0, mc = 0, mlen = 0;
        while(end < s.size()){
            cnt[s[end] - 'A']++;
            mc = max(mc, cnt[s[end] - 'A']);
            if(end - start + 1 - mc > k){
                cnt[s[start] - 'A']--;
                start++;
            }
            mlen = max(mlen, end - start + 1);
            end++;
        }
        return mlen;
    }
};
