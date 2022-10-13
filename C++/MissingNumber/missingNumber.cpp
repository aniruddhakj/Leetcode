// Author : Aniruddha Krishna Jha
// Date : 29/03/2022

/*******************************************************************************
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Example:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 
2 is the missing number in the range since it does not appear in nums.
*******************************************************************************/

cclass Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missingNumber = 0, n = nums.size();
        int sum = (n *(n + 1))/2; // find sum of n numbers where n is the array size
        for(int i = 0; i < nums.size(); i++){
            missingNumber += nums[i];
        }
        // subtract the array sum from the natural number sum to get the missing number
        missingNumber = sum - missingNumber; 
        return missingNumber;
    }
};
