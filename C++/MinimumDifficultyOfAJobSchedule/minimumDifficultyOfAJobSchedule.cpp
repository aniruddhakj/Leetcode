// Author : Aniruddha Krishna Jha
// Date : 16/10/2022

/*******************************************************************************
You want to schedule a list of jobs in d days. Jobs are dependent 
(i.e To work on the ith job, you have to finish all the jobs j where 0 <= j < i).

You have to finish at least one task every day. 
The difficulty of a job schedule is the sum of difficulties of each day of the d days. 
The difficulty of a day is the maximum difficulty of a job done on that day.

You are given an integer array jobDifficulty and an integer d. 
The difficulty of the ith job is jobDifficulty[i].

Return the minimum difficulty of a job schedule. 
If you cannot find a schedule for the jobs return -1.


Example 1:

Input: jobDifficulty = [6,5,4,3,2,1], d = 2
Output: 7
Explanation: First day you can finish the first 5 jobs, total difficulty = 6.
Second day you can finish the last job, total difficulty = 1.
The difficulty of the schedule = 6 + 1 = 7 

Example 2:

Input: jobDifficulty = [9,9,9], d = 4
Output: -1
Explanation: If you finish a job per day you will still have a free day. you cannot find a schedule for the given jobs.
*******************************************************************************/

//INTUITION: Bottom dp, with dp[i] telling min difficulty
// if work is started at ith job with d days left

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        // initialise x with a large value but not close to INT_MAX
        //as updating dp[i] with throw overflow error
        int n = jobDifficulty.size(), x = 1e8, maxDiff;
        
        // less jobs than days provided
        if(n < d) return -1;
        vector<int>dp(n + 1, x);
        dp[n] = 0;
        for(int day = 1; day < d + 1; ++day){
            for(int i = 0; i < n + 1 - day; ++i){
                maxDiff = 0;
                dp[i] = x;
                for(int j = i; j < n + 1 - day; ++j){
                    //update max difficulty and dp[i]
                    maxDiff = max(maxDiff, jobDifficulty[j]); 
                    dp[i] = min(dp[i], dp[j + 1] + maxDiff);
                }
            }
        }
        return dp[0];
    }
};
