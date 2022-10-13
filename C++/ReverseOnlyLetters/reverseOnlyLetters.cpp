// Author : Aniruddha Krishna Jha
// Date : 14/09/2021

/*******************************************************************************
 * Given a string s, reverse the string according to the following rules:
 * All the characters that are not English letters remain in the same position.
 * All the English letters (lowercase or uppercase) should be reversed.
 * Return s after reversing it.
 * Example :
 * Input: s = "a-bC-dEf-ghIj"
 * Output: "j-Ih-gfE-dCba"    
*******************************************************************************/


class Solution {
public:
    bool is_char(char t)
    {
        if(t>='a'&&t<='z')
            return true;
        else if(t>='A'&&t<='Z')
            return true;
        return false;
    }
    string reverseOnlyLetters(string S){
        char *pStart = &S[0], *pEnd = &S[S.length() - 1], temp;
        while(pEnd > pStart){
            if(!is_char(*pStart))
                *pStart++;
            else if (!is_char(*pEnd))
                *pEnd--;
            else{
                temp = *pStart;
                *pStart++ = *pEnd;
                *pEnd-- = temp;
            }
        } 
        return S;
    }
};