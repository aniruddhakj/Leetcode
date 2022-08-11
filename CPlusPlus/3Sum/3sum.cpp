// Author : Aniruddha Krishna Jha
// Date : 09/08/2022

/*******************************************************************************
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 
Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

*******************************************************************************/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; ++i){
            if(i > 0 && nums[i-1] == nums[i])
                continue;
            int l = i + 1, r = n - 1;
            //fix i and apply same logic as two sum - II
            while(l < r){
                int threeSum = nums[i] + nums[l] + nums[r];
                if(threeSum < 0 )
                    ++l;
                else if(threeSum > 0)
                    --r;
                else{
                    res.push_back({nums[i], nums[l++], nums[r]});   
                    while(nums[l] == nums[l-1] && l<r)
                        ++l;
                }
                  
            }
        }
        return res;
    }
};
