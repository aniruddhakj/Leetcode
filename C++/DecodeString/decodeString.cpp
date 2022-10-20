// Author : Aniruddha Krishna Jha
// Date : 20/10/2022

/*******************************************************************************
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. 
Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. 
Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. 
For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"

Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
*******************************************************************************/

//INTUITION: Simple max heap with stones, y and x at top

class Solution {
public:
    string helper(const string &s, int &i){

        string res;
        while(i < s.size() && s[i] != ']'){
            // if its a letter, push to res
            if(!isdigit(s[i])) res += s[i++];
            
            else {
                int n = 0;
                while (i < s.length() && isdigit(s[i]))
                    n = n * 10 + s[i++] - '0';
                    
                i++; // '['
                string t = helper(s, i);
                i++; // ']'
                
                while (n-- > 0) res += t;
            }
        }
        
        return res;
    }
    
    string decodeString(string s) {
        int i = 0;
        return helper(s, i);
    }
};
