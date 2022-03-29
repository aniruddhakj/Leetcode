// Author : Aniruddha Krishna Jha
// Date : 29/03/2022

/*******************************************************************************
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 
Example:

Input: nums = [1,3,4,2,2]
Output: 2
*******************************************************************************/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() > 1){
            int slow = nums[0];
            int fast = nums[nums[0]];
            while(slow != fast){
                slow = nums[slow];
                fast = nums[nums[fast]];
            }
          //While fast and slow match run this loop
            fast = 0;
            while(fast!= slow){
                fast = nums[fast];
                slow = nums[slow];
            }
            return slow;
        }
        return -1;
    }
};
