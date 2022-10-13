// Author : Aniruddha Krishna Jha
// Date : 12/10/2022

/*******************************************************************************
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*******************************************************************************/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        
        sort(strs.begin(), strs.end());
        
        //once sorted, first and last will most different from each other
        string first = strs[0];
        string last = strs[n - 1];
        
        int i =0;
        while(i < first.size()){
            if(first[i] == last[i]) i++;
            else break;
        }
        
        return i == 0? "": first.substr(0, i);
    }
};
