// Author : Aniruddha Krishna Jha
// Date : 25/03/2022

/*******************************************************************************
Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example :

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
*******************************************************************************/

class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == ' ') {
                reverse(s.begin() + i, s.begin() + j);
                i = j + 1;
            }
        }
        reverse(s.begin() + i, s.end());
        return s;
    }
};
