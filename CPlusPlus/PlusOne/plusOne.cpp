// Author : Aniruddha Krishna Jha
// Date : 18/08/2021

/*******************************************************************************
Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.

Example 2:

Input: digits = [9, 9, 9]
Output: [1, 0, 0, 0]
*******************************************************************************/

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry=1;
        vector <int> v;
        while(digits.size()>0){
            int x = digits.back();
            digits.pop_back();
            x = x + carry;
            v.insert(v.begin(), x%10);
            carry = x/10;
        }
        if (carry>0){
            v.insert(v.begin(), carry);
        }
        return v;
    }
};