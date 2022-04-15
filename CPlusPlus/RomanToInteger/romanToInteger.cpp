// Author : Aniruddha Krishna Jha
// Date : 15/04/2022

/*******************************************************************************
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 
12 is written as XII, which is simply X + II. 
The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. 
However, the numeral for four is not IIII. Instead, the number four is written as IV. 
Because the one is before the five we subtract it making four. 
The same principle applies to the number nine, which is written as IX. 
There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.
*******************************************************************************/

class Solution {
public:
    int romanToInt(string s) {
        if(s.empty())
            return 0;
        int romanVal[24] = {};
        romanVal['I' - 'A'] = 1;
        romanVal['V' - 'A'] = 5;
        romanVal['X' - 'A'] = 10;
        romanVal['L' - 'A'] = 50;
        romanVal['C' - 'A'] = 100;
        romanVal['D' - 'A'] = 500;
        romanVal['M' - 'A'] = 1000;
        
        int number = 0;
        int fptr = romanVal[s.front() - 'A']; //ptr to traverse the string
        
        for(int i = 1; i < s.size(); i++){
            int curr = fptr;
            fptr = romanVal[s[i] - 'A'];
            if(fptr > curr) // example case X follows I -> 'IX'
                number -= curr;
            else
                number += curr;
        }
        // add s.back() to the sum
        return number + fptr;
    }
};
