// Author : Aniruddha Krishna Jha
// Date : 17/10/2022

/*******************************************************************************
Given two strings s and p, return an array of all the start indices of p's anagrams in s. 
You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*******************************************************************************/

// INTUITION: Hashtable to store freq of char in p
// sliding window to get the indices from s

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int slen = s.size(), plen = p.size();
        if(slen < plen) return {};
        
        vector<int> freq(26, 0) , win(26, 0);
        
        for(int i = 0; i < plen; ++i){
            freq[p[i] - 'a']++;
            //setup initial window here
            win[s[i] - 'a']++;
        }
        
        vector<int> res;
        if(freq == win) res.push_back(0);
        
        for(int i = plen; i < slen; ++i){
            win[s[i - plen] - 'a']--; //window moves reset out of win frequency
            win[s[i] - 'a']++;
            
            if(freq == win) res.push_back(i - plen + 1); //push starting index
        }
        
        return res;
    }
};
