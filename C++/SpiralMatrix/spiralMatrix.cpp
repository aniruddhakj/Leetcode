// Author : Aniruddha Krishna Jha
// Date : 21/10/2022

/*******************************************************************************
Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
*******************************************************************************/

// INTUITION: order is always right->down->left->up
// record the offset for dirs, and step[2] to store shifts 
// for horizontal and vertical movements, 

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int> > dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> res;
        int r = matrix.size(), c = matrix[0].size();      
        // if (r == 0 || c == 0) return res;
        
        vector<int> step {c, r - 1};

        int idx = 0;   // index of direction.
        int rIdx = 0, cIdx = -1;    // initial position
        while (step[idx % 2] != 0) {
            for (int i = 0; i < step[idx % 2]; ++i) {
                rIdx += dir[idx][0]; 
                cIdx += dir[idx][1];
                res.push_back( matrix[rIdx][cIdx]);
            }
            step[idx % 2]--;
            idx = (idx + 1) % 4;
        }
        return res;
    }
};
