// Author : Aniruddha Krishna Jha
// Date : 23/03/2022

/*******************************************************************************
Given an array, rotate the array to the right by k steps, where k is non-negative.

Example:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

*******************************************************************************/

class Solution {
public:
    void reverse(vector<int>& nums, int start, int end){
        while(start < end){
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size()-1;
        reverse(nums, 0, nums.size()-1);
        reverse(nums, 0, k);
        reverse(nums, k+1, nums.size()-1);   
    }
};
