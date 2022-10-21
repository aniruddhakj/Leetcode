// Author : Aniruddha Krishna Jha
// Date : 21/10/2022

/*******************************************************************************
You have a 2-D grid of size m x n representing a box, and you have n balls. 
The box is open on the top and bottom sides.

Each cell in the box has a diagonal board spanning two corners of the cell that can redirect a ball to the right or to the left.

A board that redirects the ball to the right spans the top-left corner to the bottom-right corner and is represented in the grid as 1.
A board that redirects the ball to the left spans the top-right corner to the bottom-left corner and is represented in the grid as -1.
We drop one ball at the top of each column of the box. Each ball can get stuck in the box or fall out of the bottom. 
A ball gets stuck if it hits a "V" shaped pattern between two boards or if a board redirects the ball into either wall of the box.

Return an array answer of size n where answer[i] is the column that the ball falls out of at the bottom 
after dropping the ball from the ith column at the top, or -1 if the ball gets stuck in the box.


Example:

Input: grid = [[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],[-1,-1,-1,-1,-1]]
Output: [1,-1,-1,-1,-1]
Explanation: This example is shown in the photo.
Ball b0 is dropped at column 0 and falls out of the box at column 1.
Ball b1 is dropped at column 1 and will get stuck in the box between column 2 and 3 and row 1.
Ball b2 is dropped at column 2 and will get stuck on the box between column 2 and 3 and row 0.
Ball b3 is dropped at column 3 and will get stuck on the box between column 2 and 3 and row 0.
Ball b4 is dropped at column 4 and will get stuck on the box between column 2 and 3 and row 1.
*******************************************************************************/

// INTUITION: if adjacent is cell is not in same direction, ball will be stuck
// balls are dropped at grid[0][i], track initial current
// we want to move current to some next if grid[j][current] == grid[j][next]


class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> res;
        // simulation of dropping down
        for(int i = 0; i < n; ++i) {
            int cur = i, nxt;
            for(int j = 0; j < m; ++j) {
                nxt = cur + grid[j][cur];
                // adjacent is not in same dir
                if(nxt < 0 || nxt >= n || grid[j][cur] != grid[j][nxt]){
                    cur = -1;
                    break;
                }
                // update for the next row down
                cur = nxt;
            }
            res.push_back(cur);
        }
        return res;
    }
};
