// Author   : Aniruddha Krishna Jha
// Date     : 12/08/2022
// Link     : https://leetcode.com/problems/trapping-rain-water/

/*******************************************************************************
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped.

Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
*******************************************************************************/

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1, maxL = height[l], maxR = height[r];
        int res = 0 ; //track max left and right
        while(l < r){
            //height only dependent on min(maxL, maxR) so iterate only that part
            if(maxL < maxR){
                maxL = max(maxL, height[++l]);
                res += maxL - height[l];
            }
            else{
                maxR = max(maxR, height[--r]);
                res += maxR - height[r];   
            }
        }
        return res;
    }
};
