// Author   : Aniruddha Krishna Jha
// Date     : 19/04/2022
// Link     : https://leetcode.com/problems/permutation-in-string/

/*******************************************************************************
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
*******************************************************************************/

class Solution {
private:
    bool areVectorsEqual(vector<int> a, vector<int> b){
        for(int i=0; i<26; i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        //frequency maps for s1 and s2
        vector<int> mapS1(26);
        for(char c: s1) mapS1[c-'a']++;
        
        vector<int> mapS2(26);
        int i=0, j=0;
        
        while(j<s2.size()){
            mapS2[s2[j]-'a']++;
            
            if(j-i+1==s1.size()){
                if(areVectorsEqual(mapS1, mapS2)) return true;
            }
            
            if(j-i+1<s1.size()) j++;
            else{
                mapS2[s2[i]-'a']--;
                i++;
                j++;
            }
        }
        return false;
    }
};
