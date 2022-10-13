// Author : Aniruddha Krishna Jha
// Date : 12/10/2022

/*******************************************************************************
Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
 
Example 1:

Input: columnTitle = "A"
Output: 1
*******************************************************************************/

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        for(auto c : columnTitle){
            //all letters to base 26 after 1 unit
            int letter = c - 'A' + 1;
            res = res * 26 + letter;
        }
        return res;
    }
};
