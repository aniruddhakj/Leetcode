// Author : Aniruddha Krishna Jha
// Date : 17/10/2022

/*******************************************************************************
A pangram is a sentence where every letter of the English alphabet appears at least once.

Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.

Example 1:

Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
Output: true
Explanation: sentence contains at least one of every letter of the English alphabet.
Example 2:

Input: sentence = "leetcode"
Output: false
*******************************************************************************/

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> cnt(26, false);
        
        for(auto i : sentence){
            cnt[i - 'a'] = true;
        }
        
        for(auto i : cnt){
            if(!i) return false;
        }
        return true;
    }
};
