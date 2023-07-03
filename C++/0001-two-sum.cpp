// Author   : Aniruddha Krishna Jha
// Date     : 30/10/2021
// Link     : https://leetcode.com/problems/two-sum/

/*******************************************************************************
Given an array of integers nums and an integer target, 
return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*******************************************************************************/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> result{};
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i){
            int numToFind = target - nums[i];
            if( mp.find(numToFind) != mp.end() ){
                //if num is not in map, return them
                result.push_back(mp[numToFind]);
                result.push_back(i);
                return result;
            }
            mp[nums[i]] = i;
        }
        return result;
    }
};