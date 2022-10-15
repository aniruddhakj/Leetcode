// Author : Aniruddha Krishna Jha
// Date : 16/01/2022

/*******************************************************************************
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. 
In how many distinct ways can you climb to the top?

Example :
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
*******************************************************************************/

class Solution {
public:
    //This is just fibonacci a stores the current step and ways stores the total steps
    int climbStairs(int n) {
        int one = 1, two = 1;
        for(int i = 0; i < n - 1; ++i){
            int temp = one;
            one += two;
            two = temp;
        }
        return one;
    }
};
