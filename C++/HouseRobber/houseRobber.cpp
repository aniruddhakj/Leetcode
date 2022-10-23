// Author : Aniruddha Krishna Jha
// Date : 16/01/2022

/*******************************************************************************
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, 
return the maximum amount of money you can rob tonight without alerting the police.

Example:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
*******************************************************************************/

// INTUITION: 2 variables for the two paths 

class Solution {
public:
    int rob(vector<int>& nums) {
        int pre = 0, cur = 0;
        for(int n : nums) {
            int temp = max(pre + n, cur);
            pre = cur;
            cur = temp; //update rob2
        }
        return cur;
    }
};
