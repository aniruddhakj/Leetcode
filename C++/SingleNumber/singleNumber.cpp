// Author : Aniruddha Krishna Jha
// Date : 29/03/2022

/*******************************************************************************
Given a non-empty array of integers nums, every element appears twice except for one. 
Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Example:

Input: nums = [2,2,1]
Output: 1
*******************************************************************************/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(auto number: nums){
            ans ^= number;
        }
        return ans;
    }
};
