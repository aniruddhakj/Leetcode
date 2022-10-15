// Author : Aniruddha Krishna Jha
// Date : 15/10/2022

/*******************************************************************************
Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.

 

Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.

Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
*******************************************************************************/

// INTUITION: put each element in its correct place
// if we find values i and swap it with values at A[i] - 1
// example 1 at (A[1] - 1) A[0], 2 at A[1], 3 at A[2] and so on
// after the operation whichever A[i] != i + 1 is the res
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        //swap operation
        for(int i = 0; i < n; ++i){
            while(nums[i] > 0 && nums[i] < n && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        }
        
        
        //check for the smallest missing number
        for(int i = 0; i < n; ++i){
            if(nums[i] != i + 1) return i + 1;
        }
        
        return n + 1;
    }
};
