
// Author : Aniruddha Krishna Jha
// Date : 15/04/2022

/*******************************************************************************
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Example 2:

Input: nums = [1]
Output: 1
*******************************************************************************/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxTillHere = INT_MIN, cMax = 0;
        for(int currentNum: nums){
            cMax = max(currentNum, cMax+currentNum);
            maxTillHere = max(maxTillHere, cMax);
        }
        return maxTillHere;
    }
};
