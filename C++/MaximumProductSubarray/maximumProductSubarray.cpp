// Author : Aniruddha Krishna Jha
// Date : 20/10/2022

/*******************************************************************************
Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*******************************************************************************/

// INTUITION: calc prefix and suffix products
// find the max and skip if there's a zero in between

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre = 0, suf = 0, cMax = INT_MIN, n = nums.size();
        for(int i = 0; i < n; ++i){
            pre = (pre ? pre : 1) * nums[i];
            suf = (suf ? suf : 1) * nums[n-1-i];
            cMax = max({cMax, pre, suf});
        }
        return cMax;
    }
};
