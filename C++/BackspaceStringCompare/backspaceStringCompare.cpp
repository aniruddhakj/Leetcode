// Author : Aniruddha Krishna Jha
// Date : 19/10/2022

/*******************************************************************************
Given two strings s and t, return true if they are equal when both are typed into empty text editors. 
'#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".

Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
*******************************************************************************/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // k and p are to resolve backspaces in the strings s and t respectively
        int k = 0, p = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '#'){
                k--;
                k = max(0, k);
            }
            // if bksp decrement k and skip else store s[i] at s[k] and increment k
            else s[k++]=s[i];
        }
        
        for(int i = 0; i < t.size(); ++i){
            if(t[i] == '#'){
                p--;
                p = max(0, p);
            }
            else t[p++] = t[i];
        }
        
        // string's have diff length after all the backspaces resolved
        if(k != p) return false;
        
        //compare element by element
        else{
            for(int i = 0; i < k; ++i) {
                if(s[i] != t[i]) return false;
            }
            return true;
        }

    }
};
