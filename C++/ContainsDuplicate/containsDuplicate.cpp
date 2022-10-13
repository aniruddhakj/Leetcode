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
        unordered_set<int>s;
        for(int i : nums){
            if(s.find(i) != s.end()) //if i is found in set, dupe value case
                return true;
            s.insert(i); // not found, insert into set
        }
        return false; //after the pass no dupes found
    }
};
