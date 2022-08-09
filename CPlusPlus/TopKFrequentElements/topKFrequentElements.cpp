// Author : Aniruddha Krishna Jha
// Date : 09/08/2022

/*******************************************************************************
Given an integer array nums and an integer k, return the k most frequent elements.
You may return the answer in any order.
 
Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:

Input: nums = [1], k = 1
Output: [1]
*******************************************************************************/


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int>m; //map to store freq of each num
        for(int i : nums){
            m[i]++;
        }
        
        //buckets, add the num to index count(num) 
        vector<vector<int>>bucket(nums.size()+1);
        for(auto &it : m){
            bucket[it.second].push_back(it.first);
        } 
        
        vector<int> res;
        for(int i = nums.size(); i > 0; --i){
            if(res.size() >= k) //till k elements
                break;
            if(!bucket[i].empty()) //insert all values in the current bucket
                res.insert(res.end(), bucket[i].begin(), bucket[i].end());
        }
        return res;
    }
};
