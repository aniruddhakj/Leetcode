// Author : Aniruddha Krishna Jha
// Date : 23/10/2022

/*******************************************************************************
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
*******************************************************************************/

// INTUITION: Idea is to visualise and apply the 
// normal vertical multiplication method

class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        vector<int> res(m + n, 0);
        for(int i = m - 1; i >= 0; --i) {
            for(int j = n - 1; j >= 0; --j) {
                // multiplication result of x * y =  a   b stored
                //                                   |   |
                // at                               i+j i+j+1
                // tens unit wil 
                res[i + j + 1] += (num1[i]-'0') * (num2[j]-'0');
                res[i + j] += res[i + j + 1] / 10;
                res[i + j + 1] %= 10;
                
            }
        }
        
        string ans = "";
        for (int pos: res) {
            if(!(ans.size() == 0 && pos == 0)) ans += to_string(pos);
        }
        
        return !ans.size() ? "0" : ans;
    }
};
