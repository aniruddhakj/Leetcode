// Author : Aniruddha Krishna Jha
// Date : 13/10/2022

/*******************************************************************************
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:

Input: nums = [0]
Output: [[],[0]]
*******************************************************************************/

// INTUITION : For a case like [1, 2, 3...]
// initially empty power set [[]]
// then add 1 to it -> [[], [1]]
// then add 2 -> [[], [1], [2], [1, 2]]
// keep adding till end of list

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}}; 
        for(int i = 0; i <  nums.size(); ++i){
            int n = res.size(); // pow(2, i) for the ith iteration
            //backtrack
            for(int j = 0; j < n; ++j){
                res.push_back(res[j]);// for every new value empty vector will be passed
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
};
