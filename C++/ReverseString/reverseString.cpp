// Author : Aniruddha Krishna Jha
// Date : 25/03/2022

/*******************************************************************************
Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.
*******************************************************************************/

class Solution {
public:
    void reverseString(vector<char>& s) {
        //two pointers
        int start = 0, end = s.size() -1;
        while(start < end){
            swap(s[start++], s[end--]);
        }
    }
};
