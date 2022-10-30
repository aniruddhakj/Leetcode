// Author : Aniruddha Krishna Jha
// Date : 30/10/2022

/*******************************************************************************
You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). 
You can move up, down, left, or right from and to an empty cell in one step.

Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles. 
If it is not possible to find such walk return -1. 

Example 1:

Input: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
Output: 6
Explanation: 
The shortest path without eliminating any obstacle is 10.
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
*******************************************************************************/

// INTUITION: BFS and walk over as many obstacles as we can 
// result is the current path iff not able to reach the destination using the previous path.

class Solution {
public:
    int bfs (vector<vector<int>>& grid, int &k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, -1));
        queue<vector<int>>q;
        
        //q will store x, y, current path length, remaining k
        
        q.push({0, 0, 0, k});
        //run till q is empty
        while(!q.empty()) {
            auto f = q.front(); q.pop();
            int x = f[0], y = f[1];
            
            //if (x, y) outside grid, restart with new front from q
            if(x < 0 || y < 0 || x >= m || y >= n) continue;
            
            // if destination is found return current path length
            if( x == m - 1 && y == n - 1) return f[2];
            
            if(grid[x][y]) {
                // if obstacle removable, remove it
                if(f[3]) --f[3];
                
                else continue;
            }
            
            // if previously visited and obstacle removed, no need to repeat
            if(visited[x][y] != -1 && visited[x][y] >= f[3]) continue;
            
            visited[x][y] = f[3];
            
            
            // add all possible paths to the q
            q.push({x + 1, y, f[2] + 1, f[3]});
            q.push({x, y + 1, f[2] + 1, f[3]});
            q.push({x - 1, y, f[2] + 1, f[3]});
            q.push({x, y - 1, f[2] + 1, f[3]});
        }
        return -1;
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        return bfs(grid, k);
    }
};
