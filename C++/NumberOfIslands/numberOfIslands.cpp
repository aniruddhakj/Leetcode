// Author : Aniruddha Krishna Jha
// Date : 14/10/2022

/*******************************************************************************
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*******************************************************************************/

// INTUITION: same as leetcode 733 Flood fill
// Find island and mark adjacents using dfs

class Solution {
public:
    void dfs(vector<vector<char>> &A, int i, int j){
        //corner cases for coordinates
        if( i < 0 || i >= A.size() || j < 0 || j >= A[0].size()) return;
        // if not land
        if(A[i][j] != '1') return;
        
        A[i][j] = '*';
        
        //move all the directions
        dfs(A, i+1, j);
        dfs(A, i-1, j);
        dfs(A, i, j+1);
        dfs(A, i, j-1);
        
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for (int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
};
