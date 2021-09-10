// Author : Aniruddha Krishna Jha
// Date : 10/09/2021

/*******************************************************************************
Given a binary array nums, return the maximum number of consecutive 1's in the array.
->Example:

    Input: nums = [1,1,0,1,1,1]
    Output: 3
    Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3
*******************************************************************************/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums){
        int res = 0, cnt = 0;
        for(int &ele = nums){
            if(ele == 1) 
                cnt++;
            else
                cnt = 0;
            res = max(res, cnt);
        }
        return res;
    }
};