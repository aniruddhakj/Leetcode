// Author   : Aniruddha Krishna Jha
// Date     : 24/04/2022
// Link     : https://leetcode.com/problems/valid-parentheses/

/*******************************************************************************
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
 
Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "()[]{}"
Output: true
*******************************************************************************/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st; 
        for (auto ch:s){
            if(ch == '(' || ch == '{' || ch == '[') //if op bracket push
                st.push(ch);
            else{
                if(st.empty() || (st.top() == '(' && ch != ')') || (st.top() == '{' && ch != '}') ||(st.top() == '[' && ch != ']'))
                    return false; //if invalid pair return false
                st.pop(); // pop if valid pair found
            }
        }
        return st.empty(); //if anything is still in stack false else true
    }
};
