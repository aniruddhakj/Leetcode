// Author : Aniruddha Krishna Jha
// Date : 24/03/2022

/*******************************************************************************
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

Example :

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
*******************************************************************************/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int numIdx = 0, len = nums.size();
        for(auto number: nums){
            if(number)
                //insert all the non-zeros first
                nums[numIdx++] = number;
        }
        while(numIdx < len){
            nums[numIdx++] = 0;
        }
    }
};
