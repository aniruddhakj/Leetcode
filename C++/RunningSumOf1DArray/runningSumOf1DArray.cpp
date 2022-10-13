// Author : Aniruddha Krishna Jha
// Date : 01/06/2022

/*******************************************************************************
Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.

Example :

Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
*******************************************************************************/

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int prevSum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            nums[i] += prevSum;
            prevSum = nums[i];
        }
        return nums;
    }
};
