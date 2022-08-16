// Author : Aniruddha Krishna Jha
// Date : 16/08/2022

/*******************************************************************************
You are given a string s and an integer k. 
You can choose any character of the string and change it to any other uppercase English character. 
You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.


Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
*******************************************************************************/

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26, 0); //window map
        int l = 0, r = 0, mlen = 0, mc = 0 ;
    
        while(r < s.size()){
            cnt[s[r] - 'A']++;
            mc = max(mc, cnt[s[r] - 'A']); //store max freq. char
            if(r - l + 1 - mc > k){ //if maxfreq char remains in window after replacement
                cnt[s[l] - 'A']--; //move the window's left end
                l++;
            }
            mlen = max(mlen, r - l + 1); 
            r++;
               
            
        }        
        return mlen;
    }
};
