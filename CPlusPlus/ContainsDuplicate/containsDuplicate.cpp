// Author : Aniruddha Krishna Jha
// Date : 14/04/2022

/*******************************************************************************
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:

Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false
*******************************************************************************/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> unique(nums.size());
        for(int number: nums){
            auto [itr, inserted] = unique.insert(number);
            if(!inserted)
                return true;
        }
        return false;
    }
};
