// Author : Aniruddha Krishna Jha
// Date : 10/09/2021

/*******************************************************************************
Given an integer array nums sorted in non-decreasing order, 
return an array of the squares of each number sorted in non-decreasing order.
->Example:

    Input: nums = [-4,-1,0,3,10]
    Output: [0,1,9,16,100]
    Explanation: After squaring, the array becomes [16,1,0,9,100]. 
    After sorting, it becomes [0,1,9,16,100].
*******************************************************************************/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int len = nums.size();
        vector<int> result(len);
        int low = 0, high = len - 1, pos = high;
        while (low <= high){
            if(nums[low]*nums[low] >= nums[high]*nums[high]){
                result[pos] = nums[low]*nums[low];
                ++low;
            }
            else{
                result[pos] = nums[high]*nums[high];
                --high;
            }
            --pos;
        }
        return result;
    }
};