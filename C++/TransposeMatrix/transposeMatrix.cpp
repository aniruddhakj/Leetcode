// Author : Aniruddha Krishna Jha
// Date : 02/06/2022

/*******************************************************************************
Given a 2D integer array matrix, return the transpose of matrix.

The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

Example :

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]
*******************************************************************************/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rSize = matrix.size(), cSize = matrix[0].size();
        vector<vector<int>>res(cSize, vector<int>(rSize, 0));
        for(int j = 0; j < cSize; j++ ){
            for(int i = 0; i < rSize; i++)
                res[j][i] = matrix[i][j];
        }
        return res;
    }
};
