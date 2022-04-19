// Author : Aniruddha Krishna Jha
// Date : 19/04/2022

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
    vector<int> createVector(string s){
        vector<int> mapS(26);
        for(char c: s) mapS[c-'a']++;
        return mapS;
    }
    bool areVectorsEqual(vector<int> a, vector<int> b){
        for(int i=0; i<26; i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> mapS(26), mapT(26);
        mapS = createVector(s);
        mapT = createVector(t);
        return areVectorsEqual(mapS, mapT);
    }
};
