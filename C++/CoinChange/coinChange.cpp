// Author : Aniruddha Krishna Jha
// Date : 20/10/2022

/*******************************************************************************
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
*******************************************************************************/

// INTUITION: dp[i] = min(dp[i], 1 + dp[i - c])
// for each c in coins

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0; // base -> to reach 0 we need 0 coins
        for(int i = 1; i <= amount; i++){
            for(int c: coins){
                if(i >= c){
                    dp[i] = min(dp[i], 1 + dp[i-c]);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
