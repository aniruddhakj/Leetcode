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
    int climbStairs(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        int a = 1, b = 2;
        for(int i = 3; i <= n; i++){
            int c = a + b;
            a = b;
            b = c;
        }
        return b;      
    }
};