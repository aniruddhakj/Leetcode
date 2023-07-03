// Author   : Aniruddha Krishna Jha
// Date     : 10/08/2022
// Link     : https://leetcode.com/problems/product-of-array-except-self/

/*******************************************************************************
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 
Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
*******************************************************************************/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>res(nums.size());
        int pre = 1, suf = 1;
        //pass 1 to calc prefix prod
        for(int i = 0; i < nums.size(); ++i ){
            res[i] = pre;
            pre *= nums[i];
        }
        //pass 2 to calc suffix prod
        for(int j = nums.size() - 1; j >= 0; --j){
            res[j] *= suf; //in-place, multiply with prefix prod
            suf *= nums[j];
        }
        return res;
    }
};
