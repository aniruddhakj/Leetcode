// Author : Aniruddha Krishna Jha
// Date : 09/08/2022

/*******************************************************************************
Given an array of strings strs, group the anagrams together. 
You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:

Input: strs = [""]
Output: [[""]]

Example 3:

Input: strs = ["a"]
Output: [["a"]]
*******************************************************************************/

class Solution {
private:
    string getKey(string s){ 
        //Bucket sort to get the key for each string;
        vector<int>cnt(26, 0);
        for(char ch: s){
            cnt[ch - 'a']++;
        }
        string key;
        for (int i = 0; i < 26; ++i){
            key.append(to_string(cnt[i] + 'a'));
        }
        return key;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;
        for(string str : strs){
            string k = getKey(str);
            mp[k].push_back(str);
        }
        vector<vector<string>> res;
        for(auto it = mp.begin(); it != mp.end(); ++it){
            res.push_back(it->second); //push the values in map 
        }
        return res;
    }
};
