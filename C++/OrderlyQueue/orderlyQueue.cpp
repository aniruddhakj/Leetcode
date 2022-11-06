// Author : Aniruddha Krishna Jha
// Date : 06/11/2022

/*******************************************************************************
You are given a string s and an integer k. 
You can choose one of the first k letters of s and append it at the end of the string..

Return the lexicographically smallest string you could have after applying the mentioned step any number of moves.

Example 1:

Input: s = "cba", k = 1
Output: "acb"
Explanation: 
In the first move, we move the 1st character 'c' to the end, obtaining the string "bac".
In the second move, we move the 1st character 'b' to the end, obtaining the final result "acb".

Example 2:

Input: s = "baaca", k = 3
Output: "aaabc"
Explanation: 
In the first move, we move the 1st character 'b' to the end, obtaining the string "aacab".
In the second move, we move the 3rd character 'c' to the end, obtaining the final result "aaabc".
*******************************************************************************/

// INTUITION: if k is greater than 1, string can be sorted
// to optimal lexicographically smallest, else take min
// while iterating over each letter

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k > 1) {
            sort(s.begin(), s.end());
            return s;
        }
        string res = s;
        for(int i = 0; i < res.size(); ++i) {
            res = min(res, s.substr(i) + s.substr(0, i));
        }
        return res;
    }
};
