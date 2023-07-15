// Author   : Aniruddha Krishna Jha
// Date     : 30/03/2022
// Link     : https://leetcode.com/problems/search-a-2d-matrix/

/*******************************************************************************
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. 
This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

Example :
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
*******************************************************************************/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int left = 0, right = m*n -1;
        //assuming the matrix to be sorted list, binary search
        while (left != right){
            int mid = (left + right - 1) >> 1;
            if(matrix[mid/m][mid%n] < target)
                left = mid + 1;
            else 
                right = mid;
        }
        return matrix[right/m][right%m] == target;
    }
};
