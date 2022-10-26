// Author : Aniruddha Krishna Jha
// Date : 25/10/2022

/*******************************************************************************
Given an integer array nums and an integer k, 
return true if nums has a continuous subarray of size at least two whose elements sum up to a multiple of k, or false otherwise.

An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.

Example 1:

Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.

Example 2:

Input: nums = [23,2,6,4,7], k = 6
Output: true
Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
*******************************************************************************/

// INTUITION: maintain prefix sum mod k in a map
// if val at j already exists at some i, then 
// the sub-array (i,j] contains a desired sum.



class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() < 2) return false;
        
        unordered_map<int, int>mp;
        mp[0] = -1;
        
        int pref = 0;
        for(int i = 0; i < nums.size(); ++i){
            pref += nums[i];
            
            if(k) pref %= k;
            
            // check if this is already in map
            if(mp.find(pref) != mp.end()) {
                if(i - mp[pref] > 1) return true;
            }
            // else add to the map
            else mp[pref] = i;
        }
        
        return false;
    }
};
