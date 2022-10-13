// Author : Aniruddha Krishna Jha
// Date : 13/10/2022

/*******************************************************************************
Given an array of distinct integers candidates and a target integer target, 
return a list of all unique combinations of candidates where the chosen numbers sum to target. 
You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. 
Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Example :

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
*******************************************************************************/

//INTUITION: For every number to add for reaching target sum, there are two possibility i.e
// 1. Whether to include that element
// 2. Whether not to include that element for target

class Solution {
public:
    void combination(int idx, vector<int>& arr, vector<int>& tmp, vector<vector<int>>& res, int target){
        
        //if target is zero at a pt we get ans and push back the current combi
        if(target == 0){
            res.push_back(tmp);
            return;
        } 
        
        //if target is less than 0, not possible to reach the target, return
        if(target < 0) return;
        
        //if idx goes past the size of array, no more combi possible hence return
        if(idx == arr.size()) return;
        
        // case 2 not include the element 
        // without decreasing sum we move to next idx as it won't add to sum
        combination(idx + 1, arr, tmp, res, target);
        
        // case 1 include the element towards target
        // now we will have to take ith element again as some combi
        // might help in going to target e.g 2 in [2, 2, 3] target =7
        // add to tmp and decrease target accordingly
        
        tmp.push_back(arr[idx]);
        combination(idx, arr, tmp, res, target - arr[idx]);
        tmp.pop_back(); // remove last element to backtrack
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int>tmp; //tmp to try all possible combinations
        
        combination(0, candidates, tmp, res, target); //starts with index 0
        return res;
    }
};
