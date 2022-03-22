// Author : Aniruddha Krishna Jha
// Date : 22/03/2022

/*******************************************************************************
Given a sorted array of distinct integers and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
Example:

Input: nums = [1,3,5,6], target = 5
Output: 2

*******************************************************************************/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, mid;
        while(low <= high){
            mid = low + (high - low)/2;
            if(nums[mid] == target) return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else 
                high = mid - 1;
        }
        return low;
    }
};
