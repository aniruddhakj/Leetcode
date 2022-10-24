// Author : Aniruddha Krishna Jha
// Date : 24/10/2022

/*******************************************************************************
// Author : Aniruddha Krishna Jha
// Date : 23/10/2022

/*******************************************************************************
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:
Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
*******************************************************************************/

// INTUITION: dp[i] = true if valid word seq ends there. 
// The optimization is to look from current position i back and only substring 
// and do dict lookup in case the prev j with dp[j] == true.


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for(int i = 1; i < n + 1; ++i) {
            for(int j = 0; j < i; ++j) {
                if(dp[j]) {
                    string word = s.substr(j, i - j);

                    if(find(wordDict.begin(), wordDict.end(), word) != wordDict.end()) {
                        dp[i] = true; 
                        break;
                    }
                }
            }
        }

        return dp[n];
    }
};
*******************************************************************************/

// INTUITION: brute force dfs

class Solution {
public:
    int maxLength(vector<string>& arr, string str = "", int index = 0) {
	    // set to check for distinct
        unordered_set<char>s(str.begin(), str.end());
        if (s.size() != ((int)str.size())) 
            return 0;
        
        int res = str.size(); 
        for (int i = index; i < arr.size(); i++)
            res = max(res, maxLength(arr, str+arr[i], i+1));

        return res;
    }
};
