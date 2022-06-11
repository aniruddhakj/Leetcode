// Author : Aniruddha Krishna Jha
// Date : 11/06/2022

/*******************************************************************************
You are given an integer array nums and an integer x. 
In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. 
Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

 
Example 1:

Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.

Example 2:

Input: nums = [5,6,7,8,9], x = 4
Output: -1
*******************************************************************************/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0, len = nums.size();
        sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum - x;
        int cSum = 0, maxLen = 0, startIdx = 0;
        bool found = false;
        for (int endIdx = 0; endIdx < len; endIdx++) {
            cSum += nums[endIdx];
            while (startIdx <= endIdx && cSum > target) {
                cSum -= nums[startIdx];
                ++startIdx;
            }
            if (cSum == target) {
                found = true;
                maxLen = max(maxLen, endIdx - startIdx + 1);
            }
        }
        return found ? len - maxLen : -1;
    }
};
