// Author : Aniruddha Krishna Jha
// Date : 10/09/2021

/*******************************************************************************
Given an array nums of integers, return how many of them contain an even number of digits.
->Example:

    Input: nums = [555,901,482,1771]
    Output: 1 
    Explanation: Only 1771 contains an even number of digits.
*******************************************************************************/
class Solution {
public:
    int numOfDigits(int number){
        if (number < 10){
            return 1;
        }
        return (1 + numOfDigits(number/10));
    }
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for(int &ele : nums){
            if ( (numOfDigits(ele) & 1) == 0)
                ++res;
        }
        return res;    
    }
};